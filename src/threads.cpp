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

void UDP_Thread::thread_start() {
    pthread_create(&thread, NULL, &UDP_Thread::enter_handler, NULL);
    return;
}

void *UDP_Thread::handler(void) {
    std::cout << "Hello, world! OMG UDP" << std::endl;
    return 0;
}

void *UDP_Thread::enter_handler(void *context) {
    return ((UDP_Thread *)context)->handler();
}

void Serial_Thread::thread_start() {
    pthread_create(&thread, NULL, &Serial_Thread::enter_handler, NULL);
    return;
}

void *Serial_Thread::handler(void) {
    std::cout << "Hello, world! Ho man Serial!" << std::endl;
    return 0;
}

void *Serial_Thread::enter_handler(void *context) {
    return ((Serial_Thread *)context)->handler();
}

void Log_Thread::thread_start() {
    pthread_create(&thread, NULL, &Log_Thread::enter_handler, NULL);
    return;
}

void *Log_Thread::handler(void) {
    std::cout << "Hello, world! Time for some logging" << std::endl;
    return 0;
}

void *Log_Thread::enter_handler(void *context) {
    return ((Log_Thread *)context)->handler();
}

