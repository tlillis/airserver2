#include "../include/initialization.h"
#include "../include/filter.h"
#include <sstream>

Initialization::Initialization() {
}


int Initialization::load(vector <Thread_Config> &configs) {
    
    AbstractConfiguration *cfg = new XMLConfiguration("config.xml");

    Thread_Config config;

    //int types [4] = {SERIAL_THREAD,UDP_THREAD,WEBSOCKET_THREAD,LOGGING_THREAD};

    int type = 0;
    int type_i = 0;
    std::ostringstream filter_stream;
    std::ostringstream type_stream;
    int msg_id;
    int rate;
    int msg_set;
    int msg_all;
    int got_config = 0;

    Filter filter;

    while (type < 4) {
        try {
            // Clear out type stream for new iteration
            type_stream.str("");
            type_stream.clear();

            if(type == SERIAL_THREAD) {
                type_stream << "serial_" << type_i;
                config.debug = cfg->getInt(type_stream.str() + ".debug");
                config.file = cfg->getString(type_stream.str() + ".file");
                config.format = cfg->getInt(type_stream.str() + ".format");
                config.use = cfg->getInt(type_stream.str() + ".use");
                config.interface = cfg->getInt(type_stream.str() + ".interface");
                config.baud = cfg->getInt(type_stream.str() + ".baud");
                msg_all = cfg->getInt(type_stream.str() + ".msg_all");
                msg_set = 0;
                msg_set = cfg->getInt(type_stream.str() + ".msg_set");

                filter.set_all(msg_all);

                for(int i = 0; i < msg_set; i++) {
                    filter_stream << type_stream.str() << ".filter[" << i << "]";
                    msg_id = cfg->getInt(filter_stream.str() + ".id");
                    rate = cfg->getInt(filter_stream.str() + ".rate");
                    filter.set(msg_id, rate);
                    filter_stream.str("");
                    filter_stream.clear();
                }
                config.filter = filter;
                cout << "Got serial configuration for "<< config.file << endl;
                type_i++;
                got_config++;

            }
            if(type == UDP_THREAD) {
                type_stream << "udp_" << type_i;
                config.debug = cfg->getInt(type_stream.str() + ".debug");
                config.broadcast = cfg->getInt(type_stream.str() + ".broadcast");
                config.address = cfg->getString(type_stream.str() + ".address");
                config.port_send = cfg->getInt(type_stream.str() + ".send_port");
                config.port_bind = cfg->getInt(type_stream.str() + ".bind_port");
                config.format = cfg->getInt(type_stream.str() + ".format");
                config.use = cfg->getInt(type_stream.str() + ".use");
                config.interface = cfg->getInt(type_stream.str() + ".interface");
                msg_all = cfg->getInt(type_stream.str() + ".msg_all");
                msg_set = 0;
                msg_set = cfg->getInt(type_stream.str() + ".msg_set");

                filter.set_all(msg_all);

                for(int i = 0; i < msg_set; i++) {
                    filter_stream << type_stream.str() << ".filter[" << i << "]";
                    msg_id = cfg->getInt(filter_stream.str() + ".id");
                    rate = cfg->getInt(filter_stream.str() + ".rate");
                    filter.set(msg_id, rate);
                    filter_stream.str("");
                    filter_stream.clear();
                }
                config.filter = filter;
                cout << "Got UDP configuration for "<< config.address 
                    <<" send:"<< config.port_send
                    <<" bind:"<< config.port_bind 
                    << endl;
                type_i++;
                got_config++;
            }
            if(type == WEBSOCKET_THREAD) {
                type_stream << "websocket_" << type_i;
                config.debug = cfg->getInt(type_stream.str() + ".debug");
                config.address = cfg->getString(type_stream.str() + ".address");
                config.port = cfg->getInt(type_stream.str() + ".port");
                config.format = cfg->getInt(type_stream.str() + ".format");
                config.use = cfg->getInt(type_stream.str() + ".use");
                config.interface = cfg->getInt(type_stream.str() + ".interface");
                msg_all = cfg->getInt(type_stream.str() + ".msg_all");
                msg_set = 0;
                msg_set = cfg->getInt(type_stream.str() + ".msg_set");

                filter.set_all(msg_all);

                for(int i = 0; i < msg_set; i++) {
                    filter_stream << type_stream.str() << ".filter[" << i << "]";
                    msg_id = cfg->getInt(filter_stream.str() + ".id");
                    rate = cfg->getInt(filter_stream.str() + ".rate");
                    filter.set(msg_id, rate);
                    filter_stream.str("");
                    filter_stream.clear();
                }
                config.filter = filter;
                cout << "Got WebSocket configuration for "<< config.address 
                    <<" port:"<< config.port_send
                    << endl;
                type_i++;
                got_config++;
            }
            if(type == LOGGING_THREAD) {
                type_stream << "logging_" << type_i;
                config.debug = cfg->getInt(type_stream.str() + ".debug");
                config.file = cfg->getString(type_stream.str() + ".msg");
                config.format = cfg->getInt(type_stream.str() + ".format");
                config.use = cfg->getInt(type_stream.str() + ".use");
                config.interface = cfg->getInt(type_stream.str() + ".interface");
                msg_all = cfg->getInt(type_stream.str() + ".msg_all");
                msg_set = 0;
                msg_set = cfg->getInt(type_stream.str() + ".msg_set");

                filter.set_all(msg_all);

                for(int i = 0; i < msg_set; i++) {
                    filter_stream << type_stream.str() << ".filter[" << i << "]";
                    msg_id = cfg->getInt(filter_stream.str() + ".id");
                    rate = cfg->getInt(filter_stream.str() + ".rate");
                    filter.set(msg_id, rate);
                    filter_stream.str("");
                    filter_stream.clear();
                }
                config.filter = filter;
                cout << "Got logging configuration for "<< config.file << endl;
                type_i++;
                got_config++;
            }
            configs.push_back(config);

        } catch(std::exception& e) {
            type++;
            type_i = 0;
            //std::cout << "Exception: " << e.what() << std::endl;
        }
    }    
    return got_config;
};

void Initialization::print() {

    return;
};

void Initialization::end() {
}


