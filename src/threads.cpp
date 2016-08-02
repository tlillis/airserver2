#include "../include/threads.h"

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

UDP_Thread::UDP_Thread(std::string address, uint32_t port, uint16_t thread_number){
    _address = address;
    _port = port;
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

Serial_Thread::Serial_Thread(std::string port, uint32_t baud, uint16_t thread_number){
    _port = port;
    _baud = baud;
    _thread_number = thread_number;
}

void Serial_Thread::thread_start() {
    pthread_create(&thread, NULL, &Serial_Thread::enter_handler, this);
    return;
}

void *Serial_Thread::handler(void) {
    std::cout << "Hello, world! Ho man Serial!" << std::endl;
    return 0;
}

void *Serial_Thread::enter_handler(void *context) {
    return ((Serial_Thread *)context)->handler();
}

Log_Thread::Log_Thread(std::string file, uint16_t thread_number){
    _file = file;
    _thread_number = thread_number;
}

void Log_Thread::thread_start() {
    pthread_create(&thread, NULL, &Log_Thread::enter_handler, this);
    return;
}

void *Log_Thread::handler(void) {
    std::cout << "Hello, world! Time for some logging in " << _file << std::endl;
    //Check to make new file
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

    //int count = 0;

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

