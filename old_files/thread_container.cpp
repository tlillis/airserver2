#include "../include/thread_container.h"
#include <iostream>

Thread_Container::Thread_Container() {

};

Thread_Mavlink::Thread_Mavlink(Thread_Config config) {
	filter = config.filter;
	switch(config.type ) {
		case SERIAL_THREAD:
		{
			thread = new SerialThread(			1,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.file,
												config.baud,
												config.use
												);
			break;
		}
		case UDP_THREAD:
		{
			thread = new UDPThread(				2,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.address,
												config.port_send,
												config.port_bind,
												config.broadcast,
												config.use
												);
			break;
		}
		case WEBSOCKET_THREAD:
		{
			thread = new WebSocketThread(		3,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.address,
												config.port,
												config.use
												);
			break;
		}
		case LOGGING_THREAD:
		{
			thread = new MessageLoggingThread(	4,
												config.debug,
												&lock_tosend,
												&tosend,
												config.address,
												config.use
												);
			break;
		}
	}
	
}

Thread_Json::Thread_Json(Thread_Config config) {
	filter = config.filter;
	
	filter = config.filter;
	switch(config.format) {
		case SERIAL_THREAD:
		{
			thread = new SerialThread(			1,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.file,
												config.baud,
												config.use
												);
			break;
		}
		case UDP_THREAD:
		{
			thread = new UDPThread(				2,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.address,
												config.port_send,
												config.port_bind,
												config.broadcast,
												config.use
												);
			break;
		}
		case WEBSOCKET_THREAD:
		{
			thread = new WebSocketThread(		3,
												config.debug,
												&lock_tosend,
												&lock_received,
												&tosend,
												&received,
												config.address,
												config.port,
												config.use
												);
			break;
		}
		case LOGGING_THREAD:
		{
			thread = new MessageLoggingThread(	4,
												config.debug,
												&lock_tosend,
												&tosend,
												config.address,
												config.use
												);
			break;
		}
	}
	
}

int Thread_Mavlink::send(mavlink_message_t message) {
	if(filter.check(message.msgid)) {
		if(lock_tosend.tryLock()) {
			tosend.push(message);
			lock_tosend.unlock();
			return 1;
		}
		return 0;
	}
	return 0;
}

int Thread_Json::send(mavlink_message_t message) {
	std::string json_message;
	if(filter.check(message.msgid)) {
		if(lock_tosend.tryLock()) {
			mav_to_json(message,json_message);
			tosend.push(json_message);
			lock_tosend.unlock();
			return 1;
		}
		return 0;
	}
	return 0;
}

int Thread_Mavlink::receive(mavlink_message_t &message) {
	if(lock_received.tryLock()) {
		if(!received.empty()) {
			message = received.front();
			received.pop();
			lock_received.unlock();
			return 1;
		}
		lock_received.unlock();
		return 0;
	}
	return -1;
}

int Thread_Json::receive(mavlink_message_t &message) {
	std::string json_message;
	if(lock_received.tryLock()) {
		if(!received.empty()) {
			json_message = received.front();
			received.pop();
		}
		lock_received.unlock();
		return 0;
	}
	return -1;
}

Thread_Container::~Thread_Container() {

}

Thread_Json::~Thread_Json() {

}

Thread_Mavlink::~Thread_Mavlink() {
	
}