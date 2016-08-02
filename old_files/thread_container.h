#ifndef THREAD_CONTAINER_H
#define THREAD_CONTAINER_H

#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "../include/threads.h"
#include "../include/conversions.h"
#include "../include/initialization.h"
#include "../include/filter.h"

#include <ctime>

class Thread_Container{

public:
    Thread_Container();
    Poco::Runnable * thread;
    queue <mavlink_message_t> tosend_buffer;
    virtual int send(mavlink_message_t message) =0;
    virtual int receive(mavlink_message_t &message) =0;
    virtual ~Thread_Container() =0;
protected:
	Poco::Mutex lock_tosend;
	Poco::Mutex lock_received;
    Filter filter;
};

class Thread_Mavlink : public Thread_Container{
public:
    Thread_Mavlink(Thread_Config config);
    int send(mavlink_message_t message);
    int receive(mavlink_message_t & message);
    ~Thread_Mavlink();
private:
	queue <mavlink_message_t> tosend;
    queue <mavlink_message_t> received;

};

class Thread_Json : public Thread_Container{
public:
    Thread_Json(Thread_Config config);
    int send(mavlink_message_t message);
    int receive(mavlink_message_t &message);
    ~Thread_Json();
private:
    queue <std::string> tosend;
    queue <std::string> received;
};

#endif // THREAD_CONTAINER_H