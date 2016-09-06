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

UDP_Thread::UDP_Thread(std::string address, uint32_t port_send, uint32_t port_bind, uint8_t format, uint8_t debug, uint16_t thread_number){
    _address = address;
    _port_send = port_send;
    _port_bind = port_bind;
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
    else std::cout << "UNKOWN UDP TYPE " << _format << " FOR INTERFACE " << _port_bind << std::endl;
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
    serverAddr.sin_port = htons(_port_bind);
    serverAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*Bind socket with address struct*/
    //bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

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
        usleep(100);
    }
    std::cout << "EXITING UDP JSON THREAD "<< _address << ":" << _port_bind << std::endl;
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
    serverAddr.sin_port = htons(_port_bind);
    serverAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
    
     /*Configure settings in address struct*/
    //sendAddr.sin_family = AF_INET;
    //sendAddr.sin_port = htons(_port_send);
    //sendAddr.sin_addr.s_addr = inet_addr(_address.c_str());
    //memset(sendAddr.sin_zero, '\0', sizeof sendAddr.sin_zero); 

    /*Bind socket with address struct*/
    //bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;

    std::cout << "ENTERING UDP JSON CONNECTION "<< _address << ":" << _port_bind << std::endl;

    while(1){
        /* Try to receive any incoming UDP datagram. Address and port of 
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket,buffer,100000,MSG_DONTWAIT,(struct sockaddr *)&serverAddr, &addr_size);
        //nBytes = recv(udpSocket, buffer, 100000, MSG_DONTWAIT);
        //std::cout << nBytes << std::endl;
        if(nBytes > 0) {
            for(int i = 0; i <= nBytes; i++) {
                Message message;
                mavlink_message_t mavlink_message;
                mavlink_status_t status;
                if(mavlink_parse_char(4, buffer[i], &mavlink_message, &status) > 0) {
                    applyTimestamp(message);
                    message.mavlink = mavlink_message;
                    mav_to_json(message);
                    while(try_push_input(message)) {}
                    std::cout << "GOT MESSAGE: " << message.json << std::endl;
                }
            }
        }
        
        Message message;
        if(!try_pop_ouput(message)) {
            mavlink_msg_to_send_buffer(buffer, &message.mavlink);
            //std::cout << "Trying to send " << message.
            /*Send uppercase message back to client, using serverStorage as the address*/
            sendto(udpSocket,buffer,MAVLINK_MAX_PACKET_LEN,0,(struct sockaddr *)&serverAddr,addr_size);
        }
        usleep(100);
    }
    std::cout << "EXITING UDP MAVLINK THREAD "<< _address << ":" << _port_bind << std::endl;
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
    std::cout << "EXITING SERIAL JSON THREAD "<< port << "," << baud << std::endl;
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
    std::cout << "EXITING SERIAL MAVLINK THREAD "<< port << "," << baud << std::endl;
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
    
    //const uint8_t MESSAGE_SIZE = 218;
    const uint8_t MESSAGE_SIZE = 182;
    //const uint8_t HEADER_SIZE = 4;
    
    uint8_t byte_i = 0;    
                                                    //0xFA     0x03     0xFF     0x7d     0x40     0x00
    //const uint32_t EXPECTED_HEADER = 4194369535;  //11111010 00000011 11111111 01111101 01000000 00000000  
    
    char expected_header[HEADER_SIZE];
    expected_header[0] = 0xFA;
    expected_header[1] = 0x03;
    expected_header[2] = 0xFF;
    expected_header[3] = 0x7d;
    expected_header[4] = 0x40;
    expected_header[5] = 0x00;

    
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
        if(strcmp(header, expected_header)) {
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
                                if(serial_port.read_message_raw(buf)) {
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
            }
        
        } else {
            if (serial_port.status == 1) { // Add bytes following header to message for parsing
                if(serial_port.read_message_raw(buf)) {
                    if (pFile!=NULL) {
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
                    //std::cout << buffer << std::endl;
                    vector_parse(buffer);
                    memset(buffer,0,strlen(buffer)); //reset check for header
                }
            }
        }
    }
    std::cout << "EXITING SERIAL VECTORNAV THREAD "<< port << "," << baud << std::endl;
    return;
}

void Serial_Thread::vector_parse(char buffer[218]) {
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
    float mag[3];
    float temp = 0;
    float pres = 0;
    float dtime = 0;
    float dtheta[3];
    float dvel[3];
    uint16_t ins_status = 0;
    uint32_t sync_ln_cnt = 0;
    uint64_t time_gps_pps = 0;
    int8_t utc_year = 0;
    uint8_t utc_month = 0;
    uint8_t utc_day = 0;
    uint8_t utc_hour = 0;
    uint8_t utc_min = 0;
    uint8_t utc_sec = 0;
    uint16_t utc_ms = 0;
    
    time_startup = *(uint64_t*)buffer;          // 8
    time_gps = *(uint64_t*)(buffer + 8);        // 8
    time_syncln = *(uint64_t*)(buffer + 16);    // 8
    yaw = *(float*)(buffer+24);                 // 4
    pitch = *(float*)(buffer+28);               // 4
    roll = *(float*)(buffer+32);                // 4
    qtn[0] = *(float*)(buffer+36);              // 4
    qtn[1] = *(float*)(buffer+40);              // 4
    qtn[2] = *(float*)(buffer+44);              // 4
    qtn[3] = *(float*)(buffer+48);              // 4
    rate[0] = *(float*)(buffer+52);             // 4
    rate[1] = *(float*)(buffer+56);             // 4
    rate[2] = *(float*)(buffer+60);             // 4
    latitude = *(double*)(buffer+64);           // 8
    longitude = *(double*)(buffer+72);          // 8
    altitude = *(double*)(buffer+80);           // 8
    vel[0] = *(float*)(buffer+88);              // 4
    vel[1] = *(float*)(buffer+92);              // 4
    vel[2] = *(float*)(buffer+96);              // 4
    accel[0] = *(float*)(buffer+100);           // 4
    accel[1] = *(float*)(buffer+104);           // 4
    accel[2] = *(float*)(buffer+108);           // 4
    mag[0] = *(float*)(buffer+112);             // 4
    mag[1] = *(float*)(buffer+116);             // 4
    mag[2] = *(float*)(buffer+120);             // 4
    temp = *(float*)(buffer+124);               // 4
    pres = *(float*)(buffer+128);               // 4
    dtime = *(float*)(buffer+132);              // 4
    dtheta[0] = *(float*)(buffer+136);          // 4
    dtheta[1] = *(float*)(buffer+140);          // 4
    dtheta[2] = *(float*)(buffer+144);          // 4
    dvel[0] = *(float*)(buffer+148);            // 4
    dvel[1] = *(float*)(buffer+152);            // 4
    dvel[2] = *(float*)(buffer+156);            // 4
    ins_status = *(uint16_t*)(buffer+160);      // 2
    sync_ln_cnt = *(uint32_t*)(buffer+162);     // 4
    time_gps_pps = *(uint64_t*)(buffer+166);    // 8
    utc_year = *(int8_t*)(buffer+174);          // 1
    utc_month = *(uint8_t*)(buffer+175);        // 1
    utc_day = *(uint8_t*)(buffer+176);          // 1
    utc_hour = *(uint8_t*)(buffer+177);         // 1
    utc_min = *(uint8_t*)(buffer+178);          // 1
    utc_sec = *(uint8_t*)(buffer+179);          // 1
    utc_ms = *(uint16_t*)(buffer+180);          // 1
            
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
                            time_gps_pps,
                            utc_year,
                            utc_month,
                            utc_day,
                            utc_hour,
                            utc_min,
                            utc_sec,
                            utc_ms);
                            
    //std::cout << buffer << std::endl;
                            
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
        usleep(100);
        //usleep(5000);
    }
    fclose(pFile);
    std::cout << "EXITING LOGGING THREAD "<< oss.str() << std::endl;
    return 0;
}

void *Log_Thread::enter_handler(void *context) {
    return ((Log_Thread *)context)->handler();
}

