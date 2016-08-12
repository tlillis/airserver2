#include "../include/threads.h"
#include "../include/configuration.h"
#include "../include/serial_port.h"
#include "../include/conversions.h"

uint8_t Interface_Thread::try_lock_input() {
    return pthread_mutex_trylock(&lock_input);
}

uint8_t Interface_Thread::unlock_input() {
    return pthread_mutex_unlock(&lock_input);
}

uint8_t Interface_Thread::try_lock_output() {
    return pthread_mutex_trylock(&lock_output);
}

uint8_t Interface_Thread::unlock_output() {
    return pthread_mutex_unlock(&lock_output);
}

uint8_t Interface_Thread::try_pop_ouput(Message &message) {
    if(try_lock_output()){
        if(!output_q.empty()) {
            message = output_q.front();
            output_q.pop();
            unlock_output();
            return 0;
        }
        unlock_output();
        return 1;
    }
    return 2;
}

uint8_t Interface_Thread::try_push_ouput(Message message) {
    if(try_lock_output()){
        output_q.push(message);
        unlock_output();
        return 0;
    }
    return 2;
}

uint8_t Interface_Thread::try_pop_input(Message &message) {
    if(try_lock_input()){
        if(!input_q.empty()) {
            message = input_q.front();
            input_q.pop();
            unlock_input();
            return 0;
        }
        unlock_input();
        return 1;
    }
    return 2;
}

uint8_t Interface_Thread::try_push_input(Message message) {
    if(try_lock_input()){
        input_q.push(message);
        unlock_input();
        return 0;
    }
    return 2;
}

uint8_t Interface_Thread::try_pop(Message &message) {
    return try_pop_input(message);
}

uint8_t Interface_Thread::try_push(Message message) {
    return try_push_ouput(message);
}

UDP_Thread::UDP_Thread(std::string address, uint32_t port, uint8_t format, uint8_t debug, uint16_t thread_number){
    _address = address;
    _port = port;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void UDP_Thread::thread_start() {
    pthread_create(&thread, NULL, &UDP_Thread::enter_handler, this);
    return;
}

void *UDP_Thread::handler(void) {
    std::cout << "Hello, world! OMG UDP" << std::endl;
    
    if(_format == JSON) interface_json();
    else if(_format == MAVLINK) interface_mavlink();
    else std::cout << "UNKOWN UDP TYPE " << _format << " FOR INTERFACE " << _port << std::endl;
    return 0;
}

void *UDP_Thread::enter_handler(void *context) {
    return ((UDP_Thread *)context)->handler();
}

void UDP_Thread::interface_json() {
    int udpSocket, nBytes;
    uint8_t buffer[100000];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    /*Create UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(_port);
    serverAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;

    while(1){
        /* Try to receive any incoming UDP datagram. Address and port of 
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket,buffer,100000,MSG_DONTWAIT,(struct sockaddr *)&serverAddr, &addr_size);
        if(nBytes > 0) {
            Message message;
            applyTimestamp(message);
            //json_to_mav(message);
            while(try_push_input(message)) {}
            //std::cout << "GOT MESSAGE: " << message.json << std::endl;
        }
        
        Message message;
        if(!try_pop_ouput(message)) {
            /*Send uppercase message back to client, using serverStorage as the address*/
            sendto(udpSocket,message.json.c_str(),strlen(message.json.c_str()),0,(struct sockaddr *)&serverAddr,addr_size);
            //std::cout << "SENT: " << message.json << std::endl;
        }
    }
    return;
}

void UDP_Thread::interface_mavlink() {
    int udpSocket, nBytes;
    uint8_t buffer[100000];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    /*Create UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(_port);
    serverAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;

    while(1){
        /* Try to receive any incoming UDP datagram. Address and port of 
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket,buffer,100000,MSG_DONTWAIT,(struct sockaddr *)&serverAddr, &addr_size);
        for(int i = 0; i <= nBytes; i++) {
            Message message;
            mavlink_message_t mavlink_message;
            mavlink_status_t status;
            if(mavlink_parse_char(4, buffer[i], &mavlink_message, &status) > 0) {
                applyTimestamp(message);
                message.mavlink = mavlink_message;
                mav_to_json(message);
                while(try_push_input(message)) {}
                //std::cout << "GOT MESSAGE: " << message.json << std::endl;
            }
        }
        
        Message message;
        if(!try_pop_ouput(message)) {
            mavlink_msg_to_send_buffer(buffer, &message.mavlink);
            /*Send uppercase message back to client, using serverStorage as the address*/
            sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
        }
    }
    return;
}

Serial_Thread::Serial_Thread(std::string port, uint32_t baud, uint8_t format, uint8_t debug, uint16_t thread_number){
    _port = port;
    _baud = baud;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void Serial_Thread::thread_start() {
    pthread_create(&thread, NULL, &Serial_Thread::enter_handler, this);
    return;
}

void Serial_Thread::interface_json() {
    std::cout << "JSON SERIAL THREAD" << std::endl;
    char * port = (char*)_port.c_str();
    int count_r = 0;
    int baud = _baud;

    Serial_Port serial_port(port, baud);

    //int len = 0;
    char buf;


    serial_port.start();

    while(1) {
        if (serial_port.status == 1) {
            serial_port.read_message_raw(buf);
        }
        else {
            break;
        }
        if (buf == '\n') {
            Message message;
            applyTimestamp(message);
            //message.json;
            //json_to_mav(message);
            while(try_push_input(message)) {}
            std::cout << "Got " << count_r << " messages" << std::endl;
            count_r++;
            }
        usleep(100);
    }
    return;
}

void Serial_Thread::interface_mavlink() {
    std::cout << "MAVLINK SERIAL THREAD" << std::endl;
    mavlink_message_t message_mavlink;
    char * port = (char*)_port.c_str();
    int count_r = 0;
    int baud = _baud;

    Serial_Port serial_port(port, baud);

    int len = 0;

    serial_port.start();

    while(1) {
        if (serial_port.status == 1) {
            len = serial_port.read_message_mavlink(message_mavlink,2);
        }
        else {
            break;
        }
        if (len) {
            Message message;
            applyTimestamp(message);
            message.mavlink = message_mavlink;
            mav_to_json(message);
            while(try_push_input(message)) {}
            std::cout << "Got " << count_r << " messages" << std::endl;
            count_r++;
            }
        usleep(100);
    }
    return;
}

void Serial_Thread::interface_vectornav() {
    std::cout << "VECTORNAV SERIAL THREAD" << std::endl;
    
    unsigned int file_tag = 0;
    std::ostringstream oss;

    oss << "vectornav" << file_tag << ".txt";
    while (std::ifstream(oss.str().c_str())) { //Check if file already exists
        file_tag++;
        oss.str("");
        oss.clear();
        oss << "vectornav" << file_tag << ".txt";
    }
    
    FILE* pFile;
    pFile = fopen(oss.str().c_str(), "wb");
    
    char * port = (char*)_port.c_str();
    int baud = _baud;
    
    const uint8_t MESSAGE_SIZE = 218;                                                                                                 
    //const uint8_t HEADER_SIZE = 4;
    
    uint8_t byte_i = 0;
    
                                                    //0xFA 0x01 0xFF 0xFF    
    //const uint32_t EXPECTED_HEADER = 4194435071;  //11111010 00000001 11111111 11111111
                                                    //0xFA 0x00 0xFF 0xFF    
    const uint32_t EXPECTED_HEADER = 4194369535;    //11111010 00000000 11111111 11111111
    
    char buffer[MESSAGE_SIZE];
    char header[HEADER_SIZE];

    Serial_Port serial_port(port, baud);
    char buf;

    serial_port.start();
    serial_port.read_message_raw(buf);
    if (pFile!=NULL) {
        if(fwrite(&buf, sizeof(char), 1, pFile)) {
            fflush(pFile);
        }
    }
    
    while(1) {
        std::cout << std::hex << *(uint32_t*)header << std::endl;
        if(*(uint32_t*)header != EXPECTED_HEADER) {
            if(serial_port.status == 1) {
                if(serial_port.read_message_raw(buf)) {
                    if (pFile!=NULL) {
                        if(fwrite(&buf, sizeof(char), 1, pFile)) {
                            fflush(pFile);
                        }
                    }
                    if((unsigned char) buf != 0xFA) {
                    
                    } else {
                        header[0] = 0xFA;
                        for (int i = 1;i < HEADER_SIZE; i++) { // Read 4 bytes from serial to check agaisnt expected header
                            while(serial_port.status != 1) {
                            }
                            if (serial_port.status == 1) {
                                serial_port.read_message_raw(buf);
                                if (pFile!=NULL) {
                                    if(fwrite(&buf, sizeof(char), 1, pFile)) {
                                        fflush(pFile);
                                    }
                                }
                                header[i] = (unsigned char)buf;
                            }
                        }
                    }
                }
            }
        
        } else {
            std::cout << "Serial port check" << std::endl;
            if (serial_port.status == 1) { // Add bytes following header to message for parsing
                std::cout << "Serial port read" << std::endl;
                serial_port.read_message_raw(buf);
                std::cout << "File check" << std::endl;
                if (pFile!=NULL) {
                    std::cout << "file write" << std::endl;
                    if(fwrite(&buf, sizeof(char), 1, pFile)) {
                        fflush(pFile);
                    }
                }                                        
                buffer[byte_i] = buf;
                byte_i++;
            }
            if (byte_i == MESSAGE_SIZE) { //Once the message reaches the end
                memset(header,0,strlen(header)); //reset check for header
                byte_i = 0;
                vector_parse();
            }
        }
    }
    return;
}

void Serial_Thread::vector_parse() {
    Message message;
    applyTimestamp(message);
    
    mavlink_message_t message_mavlink;
    
    int system_type = 10;                                                                                                             
    int autopilot_type = 10;
    
    uint64_t time_startup = 0;
    uint64_t time_gps = 0;
    uint64_t time_syncln = 0;
    float yaw = 0;
    float pitch = 0;
    float roll = 0;
    float qtn[4];
    float rate[3];
    double latitude = 0;
    double longitude = 0;
    double altitude = 0;
    float vel[3];
    float accel[3];
    float imu_rate[3];
    float imu_accel[3];
    float mag[3];
    float temp = 0;
    float pres = 0;
    float dtime = 0;
    float dtheta[3];
    float dvel[3];
    uint16_t ins_status = 0;
    uint32_t sync_ln_cnt = 0;
    uint64_t time_gps_pps = 0;
    
    time_startup = *(uint64_t*)buffer;
    time_gps = *(uint64_t*)(buffer + 8);
    time_syncln = *(uint64_t*)(buffer + 16);
    yaw = *(float*)(buffer+24);
    pitch = *(float*)(buffer+28);
    roll = *(float*)(buffer+32);
    qtn[0] = *(float*)(buffer+36);
    qtn[1] = *(float*)(buffer+40);
    qtn[2] = *(float*)(buffer+44);
    qtn[3] = *(float*)(buffer+48);
    rate[0] = *(float*)(buffer+52);
    rate[1] = *(float*)(buffer+56);
    rate[2] = *(float*)(buffer+60);
    latitude = *(double*)(buffer+64);
    longitude = *(double*)(buffer+72);
    altitude = *(double*)(buffer+80);
    vel[0] = *(float*)(buffer+88);
    vel[1] = *(float*)(buffer+92);
    vel[2] = *(float*)(buffer+96);
    accel[0] = *(float*)(buffer+100);
    accel[1] = *(float*)(buffer+104);
    accel[2] = *(float*)(buffer+108);
    imu_rate[0] = *(float*)(buffer+112);
    imu_rate[1] = *(float*)(buffer+116);
    imu_rate[2] = *(float*)(buffer+120);
    imu_accel[3] = *(float*)(buffer+124);
    imu_accel[4] = *(float*)(buffer+128);
    imu_accel[5] = *(float*)(buffer+132);
    mag[0] = *(float*)(buffer+136);
    mag[1] = *(float*)(buffer+140);
    mag[2] = *(float*)(buffer+144);
    temp = *(float*)(buffer+148);
    pres = *(float*)(buffer+152);
    dtime = *(float*)(buffer+156);
    dtheta[0] = *(float*)(buffer+160);
    dtheta[1] = *(float*)(buffer+164);
    dtheta[2] = *(float*)(buffer+168);
    dvel[0] = *(float*)(buffer+172);
    dvel[1] = *(float*)(buffer+176);
    dvel[2] = *(float*)(buffer+180);
    ins_status = *(uint16_t*)(buffer+184);
    sync_ln_cnt = *(uint32_t*)(buffer+186);
    time_gps_pps = *(uint64_t*)(buffer+190);
            
    mavlink_msg_vector_nav_pack(system_type, 
                            autopilot_type, 
                            &message_mavlink, 
                            time_startup, 
                            time_startup, 
                            time_gps,                                                                                        
                            time_syncln, 
                            yaw, 
                            pitch, 
                            roll,
                            qtn[0],
                            qtn[1],
                            qtn[2],
                            qtn[3],
                            rate[0],
                            rate[1],
                            rate[2],
                            latitude,
                            longitude,
                            altitude,
                            vel[0],
                            vel[1],
                            vel[2],
                            accel[0],
                            accel[1],
                            accel[2],
                            imu_rate[0],
                            imu_rate[1],
                            imu_rate[2],
                            imu_accel[0],
                            imu_accel[1],
                            imu_accel[2],
                            mag[0],
                            mag[1],
                            mag[2],
                            temp,
                            pres,
                            dtime,
                            dtheta[0],
                            dtheta[1],
                            dtheta[2],
                            dvel[0],                                                                               
                            dvel[1],
                            dvel[2],
                            ins_status,
                            sync_ln_cnt,
                            time_gps_pps);
                            
    message.mavlink = message_mavlink;
    mav_to_json(message);
    std::cout << message.json << std::endl;
}

void *Serial_Thread::handler(void) {
    std::cout << "Hello, world! Ho man Serial!" << std::endl;
    
    if(_format == JSON) interface_json();
    else if(_format == MAVLINK) interface_mavlink();
    else if(_format == VECTORNAV) interface_vectornav();
    else std::cout << "UNKOWN SERIAL TYPE " << _format << " FOR INTERFACE " << _port << std::endl;
    
    return 0;
}

void *Serial_Thread::enter_handler(void *context) {
    return ((Serial_Thread *)context)->handler();
}

Log_Thread::Log_Thread(std::string file, uint8_t format, uint8_t debug, uint16_t thread_number){
    _file = file;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void Log_Thread::thread_start() {
    pthread_create(&thread, NULL, &Log_Thread::enter_handler, this);
    return;
}

void *Log_Thread::handler(void) {
    std::cout << "Hello, world! Time for some logging in " << _file << std::endl;
    // Check to make new file
    unsigned int file_tag = 0;
    std::ostringstream oss;

    oss << _file << file_tag << ".txt";
    while (std::ifstream(oss.str().c_str())) { //Check if file already exists
        file_tag++;
        oss.str("");
        oss.clear();
        oss << _file << file_tag << ".txt";
    }

    std::string message;

    // int count = 0;

    FILE* pFile;
    pFile = fopen(oss.str().c_str(), "wb");

    while (1) {
        if (pFile!=NULL) {
            Message message;
            if(!try_pop_ouput(message)) {
                if(fwrite(message.json.c_str(), 1, strlen(message.json.c_str()), pFile)) {
                    fwrite("\n", sizeof(char), 1, pFile);
                    fflush(pFile);
                    //count++;
                }
            }
        }
        //usleep(5000);
    }
    fclose(pFile);
    return 0;
}

void *Log_Thread::enter_handler(void *context) {
    //std::cout << "HEYHYEHYE" << _file << std::endl;
    return ((Log_Thread *)context)->handler();
}

