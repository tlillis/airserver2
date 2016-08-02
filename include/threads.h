#include <iostream>
#include <queue>
#include <string>
#include <stdint.h>

#include "../include/messages.h"

using namespace std;

class Interface_Thread {
    protected:
    
        friend void* ThreadEntryFunc(void *);
        
        std::queue <string> input_q;
        std::queue <string> ouput_q;
        
        pthread_t thread;
        pthread_mutex_t lock;
        
        uint8_t format;
        std::string interface;
        //Filter filter;
        uint8_t debug;
        uint16_t thread_number;
    
        virtual void *communicate() {return 0;}
        void* do_action(void* arg);
    
        uint8_t try_lock();
        uint8_t unlock();
    
    public:
        void thread_start();
        void thread_end();
        
        uint8_t try_pop(Message &message);
        uint8_t try_push(Message message);
};

class UDP_Thread: public Interface_Thread {
    private:
        uint32_t port;
        uint32_t port_send;
        uint32_t port_bind;
        uint8_t broadcast;
        void *communicate();
    public:
        void set_options(std::string address, uint32_t port, uint16_t thread_number);
};

class Serial_Thread: public Interface_Thread {
    private:
        uint32_t baud;
        void *communicate();
    public:
        void set_options(std::string file, uint32_t baud, uint16_t thread_number);
};

class Log_Thread: public Interface_Thread {
    private:
        void *communicate();
    public:
        void set_options(std::string file, uint16_t thread_number);
};

class Congregation_Thread {
    protected:
        std::queue <string> message_q;

    public:
        void start_thread();
};
