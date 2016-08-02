#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

#include "../include/thread_container.h"
#include "../include/filter.h"

class Thread_Handler {

public:
    Thread_Handler(vector <Thread_Config> configs);
    int collect(mavlink_message_t &message);
    int prepare(mavlink_message_t message);
    ~Thread_Handler();
    queue <mavlink_message_t> received;

private:
	vector <Thread_Container*> threads;
	Poco::ThreadPool pool;
	

};

#endif // THREAD_HANDLER_H