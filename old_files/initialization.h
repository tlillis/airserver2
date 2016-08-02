#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "../include/filter.h"

#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"

#include <Poco/Util/AbstractConfiguration.h>
#include <Poco/Util/XMLConfiguration.h>

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

#define SERIAL_THREAD 0
#define UDP_THREAD 1
#define WEBSOCKET_THREAD 2
#define LOGGING_THREAD 3

#define MAVLINK 0
#define JSON 1


using namespace Poco::Util;
using namespace std;

using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;

struct Thread_Config {
    int format;
    int type;
    int direction;
    int interface;
    Filter filter;
    int debug;
    std::string file;
    std::string address;
    int port;
    int port_send;
    int port_bind;
    int broadcast;
    int baud;
    int use;
};

struct Initialization {

    Initialization();

    int load(vector <Thread_Config> &configs);
    void print();
        void end();



    int debug;
};

#endif // CONFIGURATION_H
