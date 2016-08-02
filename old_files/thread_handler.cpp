#include "../include/thread_handler.h"
#include <iostream>

Thread_Handler::Thread_Handler(vector <Thread_Config> configs) {
	for(unsigned int i = 0; i < configs.size(); i++) {
		Thread_Container *thread = NULL;
		if(configs[i].format == MAVLINK) {
			thread = new Thread_Mavlink(configs[i]);
			cout << "MAVLINK" << endl;
		} 
		if(configs[i].format == JSON) {
			thread = new Thread_Json(configs[i]);
			cout << "JSON" << endl;
		}

		if(thread != NULL) {
			threads.push_back(thread);
			pool.start(*(thread->thread));
		}
	}
};

int Thread_Handler::collect(mavlink_message_t &message) {
	mavlink_message_t temp;
	for(unsigned int i = 0; i < threads.size(); i++) {
		if(threads[i]->receive(temp) == 1) {
			received.push(temp);
		}
	}
	if(!received.empty()) {
		message = received.front();
		received.pop();
	} else {
		return -1;
	}
	return 0;
}

int Thread_Handler::prepare(mavlink_message_t message) {
	for(unsigned int i = 0; i < threads.size(); i++) {
		threads[i]->tosend_buffer.push(message);
		if(threads[i]->send(threads[i]->tosend_buffer.front())) {
			threads[i]->tosend_buffer.pop();
		}
		//received.pop();
	}
	return 0;
}

Thread_Handler::~Thread_Handler() {
	for(unsigned int i = 0; i < threads.size(); i++) {
		delete threads[i];
	}
}