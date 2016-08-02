#ifndef THREADS_H
#define THREADS_H

#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/NetException.h"

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"

#include "serial_port.h"
#include "websocket.h"

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using Poco::Net::ServerSocket;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::WebSocketException;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Net::WebSocket;
using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

class SerialThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
        std::queue <mavlink_message_t> * _tosend_mav;
    std::queue <mavlink_message_t> * _received_mav;
    std::queue <std::string> * _tosend_str;
    std::queue <std::string> * _received_str;
    std::string _file;
    int _baud;
    int _use;
public:
    // json constr
    SerialThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received, 
                                                std::queue <std::string> * tosend_str,
                                                std::queue <std::string> * received_str,
                                                std::string file, int baud, int use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend_str(tosend_str), _received_str(received_str),
                                                _file(file), _baud(baud), _use(use){}

    // mav constr
    SerialThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received, 
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string file, int baud, int use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class WebSocketThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <std::string> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::queue <std::string> * _tosend_str;
    std::queue <std::string> * _received_str;
    std::queue <mavlink_message_t> * _tosend_mav;
    std::queue <mavlink_message_t> * _received_mav;
    std::string _address;
    int _port;
    int _use;
public:
    // json constr
    WebSocketThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <std::string> * tosend_str,
                                                std::queue <std::string> * received_str,
                                                std::string address, int port, int use)
    : _id(id),  _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend_str(tosend_str),_received_str(received_str),
                                                _address(address), _port(port), _use(use){}
    // mavlink constr
    WebSocketThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <mavlink_message_t> * tosend_mav,
                                                std::queue <mavlink_message_t> * received_mav,
                                                std::string address, int port, int use)
    : _id(id),  _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend_mav(tosend_mav),_received_mav(received_mav),
                                                _address(address), _port(port), _use(use){}

    // temp remove after finished!!
    WebSocketThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <std::string> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port, int use)
    : _id(id),  _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend),_received(received),
                                                _address(address), _port(port), _use(use){}
    void run();
};

class UDPThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::queue <std::string> * _tosend_str;
    std::queue <std::string> * _received_str;
    std::string _address;
    int _port_send;
    int _port_bind;
    int _broadcast;
    int _use;
public:
    //Mavlink constr
    UDPThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port_send, int port_bind, int broadcast, int use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _address(address), _port_send(port_send), _port_bind(port_bind), _broadcast(broadcast), _use(use){}
    //json constr
    UDPThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <std::string> * tosend_str,
                                                std::queue <std::string> * received_str,
                                                std::string address, int port_send, int port_bind, int broadcast, int use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend_str(tosend_str), _received_str(received_str),
                                                _address(address), _port_send(port_send), _port_bind(port_bind), _broadcast(broadcast), _use(use){}
    void run();
};

class MessageLoggingThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock;
    std::queue <std::string> * _tolog;
    std::queue <mavlink_message_t> * _tolog_mav;
    std::string _address;
    int _use;
public:
    //json constr
    MessageLoggingThread (int id, int debug, Poco::Mutex * lock, std::queue <std::string> * tolog,
                                                std::string address, int use)
    : _id(id), _debug(debug), _lock(lock), _tolog(tolog), _address(address), _use(use){}
    //mavlink constr
    MessageLoggingThread (int id, int debug, Poco::Mutex * lock, std::queue <mavlink_message_t> * tolog_mav,
                                                std::string address, int use)
    : _id(id), _debug(debug), _lock(lock), _tolog_mav(tolog_mav), _address(address), _use(use){}
    void run();
};

#endif // THREADS_H