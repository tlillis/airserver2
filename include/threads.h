#ifndef THREADS_H
#define THREADS_H

#include <iostream>
#include <queue>
#include <string>
#include <stdint.h>
#include <sstream>
#include <fstream>

#include "../include/messages.h"

using namespace std;

class Interface_Thread {
    protected:
        std::queue <string> input_q;
        std::queue <string> ouput_q;
        
        pthread_t thread;
        pthread_mutex_t lock;
        
        uint8_t format;
        std::string interface;
        //Filter filter;
        uint8_t debug;
        uint16_t thread_number;
    
        //virtual void *communicate() {return 0;}
        void* do_action(void* arg);
    
        uint8_t try_lock();
        uint8_t unlock();
    
    public:
        virtual void thread_start() {return;}
        virtual void thread_end() {return;}
        
        uint8_t try_pop(Message &message);
        uint8_t try_push(Message message);
};

class UDP_Thread: public Interface_Thread {
    private:
        uint32_t _port;
        uint32_t _port_send;
        uint32_t _port_bind;
        uint8_t _broadcast;
        std::string _address;
        uint16_t _thread_number;
        void *handler(void);
        static void *enter_handler(void *context);
    public:
        UDP_Thread(std::string address, uint32_t port, uint16_t thread_number);
        void thread_start();
};

class Serial_Thread: public Interface_Thread {
    private:
        uint32_t _baud;
        std::string _port;
        uint16_t _thread_number;
        void *handler(void);
        static void *enter_handler(void *context);
    public:
        Serial_Thread(std::string port, uint32_t baud, uint16_t thread_number);
        void thread_start();
};

class Log_Thread: public Interface_Thread {
    private:
        std::string _file;
        uint16_t _thread_number;
        void *handler(void);
        static void *enter_handler(void *context);
    public:
        Log_Thread(std::string file, uint16_t thread_number);
        void thread_start();
};

class Congregation_Thread {
    protected:
        std::queue <string> message_q;

    public:
        void start_thread();
};

#endif // THREADS_H
