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
    struct sockaddr_storage serverStorage;
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
    addr_size = sizeof serverStorage;

    while(1){
        /* Try to receive any incoming UDP datagram. Address and port of 
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket,buffer,100000,0,(struct sockaddr *)&serverStorage, &addr_size);
        for(int i = 0; i <= nBytes; i++) {
            Message message;
            mavlink_message_t mavlink_message;
            mavlink_status_t status;
            if(mavlink_parse_char(4, buffer[i], &mavlink_message, &status) > 0) {
                applyTimestamp(message);
                message.mavlink = mavlink_message;
                mav_to_json(message);
                while(try_push_input(message)) {}
                std::cout << "GOT MESSAGE: " << mavlink_message.msgid << std::endl;
            }
        }
        
        Message message;
        if(!try_pop_ouput(message)) {
            mavlink_msg_to_send_buffer(buffer, &message.mavlink);
            /*Send uppercase message back to client, using serverStorage as the address*/
            sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
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
    char * port = (char*)_port.c_str();
    int count_r = 0;
    int baud = _baud;

    Serial_Port serial_port(port, baud);
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
            //json_to_mav(message);
            while(try_push_input(message)) {}
            std::cout << "Got " << count_r << " messages" << std::endl;
            count_r++;
            }
        usleep(100);
    }
    return;
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

