#include "../include/threads.h"
#include "../include/configuration.h"
#include "../include/serial_port.h"

uint8_t Interface_Thread::try_lock() {
    return 0;
}

uint8_t Interface_Thread::unlock() {
    return 0;
}

uint8_t Interface_Thread::try_pop(Message &message) {
    return 0;
}

uint8_t Interface_Thread::try_push(Message message) {
    return 0;
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
    return 0;
}

void *UDP_Thread::enter_handler(void *context) {
    return ((UDP_Thread *)context)->handler();
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
    
    return;
}

void Serial_Thread::interface_mavlink() {
    std::cout << "MAVLINK SERIAL THREAD" << std::endl;
    Message message;
    mavlink_message_t message_mavlink;
    char * port = (char*)_port.c_str();
    int count_r = 0;
    int baud = _baud;

    Serial_Port serial_port(port, baud);

    int len = 0;

    int gotData = 0;

    serial_port.start();
        
    //while(!gotData) {
    //    serial_port.start();
    //    gotData = serial_port.read_message_mavlink(message_mavlink,2);
    //    if(!gotData) {
    //        serial_port.stop();
    //    }
    //}
        
    std::cout << port << " GOT MAVLINK DATA" << std::endl;

    while(1) {
        if (serial_port.status == 1) {
            len = serial_port.read_message_mavlink(message_mavlink,2);
        }
        else {
            break;
        }
        if (len) {
            applyTimestamp(message);
            message.mavlink = message_mavlink;
            if(true) std::cout << "Got " << count_r << " messages" << std::endl;
            count_r++;
            }
        usleep(100);
    }
    return;
}

void Serial_Thread::interface_vectornav() {
    
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
            //if(fwrite(message.c_str(), 1, strlen(message.c_str()), pFile)) {
                //fwrite("\n", sizeof(char), 1, pFile);
                //fflush(pFile);
                //count++;
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

