#ifndef THREADS_H
#define THREADS_H

#include <iostream>
#include <queue>
#include <string>
#include <stdint.h>
#include <sstream>
#include <fstream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../include/messages.h"

using namespace std;

class Interface_Thread {
    protected:
        std::queue <Message> input_q;
        std::queue <Message> output_q;
        
        pthread_t thread;
        pthread_mutex_t lock_output;
        pthread_mutex_t lock_input;
        
        uint8_t _format;
        uint8_t _debug;
        uint16_t _thread_number;
        
        uint8_t try_lock_output();
        uint8_t unlock_output();
        
        uint8_t try_lock_input();
        uint8_t unlock_input();
        
        uint8_t try_pop_ouput(Message &message);
        uint8_t try_push_ouput(Message message);
        
        uint8_t try_pop_input(Message &message);
        uint8_t try_push_input(Message message);
    
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
        void *handler(void);
        static void *enter_handler(void *context);
        void interface_mavlink();
        void interface_json();
    public:
        UDP_Thread(std::string address, uint32_t port, uint8_t format, uint8_t debug, uint16_t thread_number);
        void thread_start();
};

class Serial_Thread: public Interface_Thread {
    private:
        uint32_t _baud;
        std::string _port;
        void *handler(void);
        static void *enter_handler(void *context);
        void interface_json();
        void interface_mavlink();
        void interface_vectornav();
    public:
        Serial_Thread(std::string port, uint32_t baud, uint8_t format, uint8_t debug, uint16_t thread_number);
        void thread_start();
};

class Log_Thread: public Interface_Thread {
    private:
        std::string _file;
        void *handler(void);
        static void *enter_handler(void *context);
    public:
        Log_Thread(std::string file, uint8_t format, uint8_t debug, uint16_t thread_number);
        void thread_start();
};

class Congregation_Thread {
    protected:
        std::queue <string> message_q;

    public:
        void start_thread();
};

#endif // THREADS_H
