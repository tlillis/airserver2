#include "../include/threads.h"

void* ThreadEntryFunc(void *obj_param) {
    Interface_Thread *thr  = ((Interface_Thread *)obj_param); 

    //access all the members using thr->

    return NULL;
}


void Interface_Thread::thread_start() {
    //pthread_create(thread,NULL,Interface_Thread::communicate,NULL);
    //pthread_create(&thread, NULL, &Interface_Thread::odo_action, this);
    pthread_create(&thread, NULL, &ThreadEntryFunc, this);
    return;
}


void* Interface_Thread::do_action(void* arg) {
    return static_cast<Interface_Thread*>(arg)->communicate();
}

void Interface_Thread::thread_end() {
    return;
}

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

void *UDP_Thread::communicate() {
    
    return 0;
}

void *Serial_Thread::communicate() {
    return 0;
}

void *Log_Thread::communicate() {
    return 0;
}

