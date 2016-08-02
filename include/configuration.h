#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <stdint.h>
#include <vector>

#include "../include/threads.h"

#define SERIAL 0
#define UDP 1
#define LOGGING 3

#define MAVLINK 0
#define JSON 1
#define VECTORNAV 2

#define IN 0
#define OUT 1


struct Thread_Config {
    uint8_t format;
    uint8_t type;
    uint8_t direction;
    std::string interface;
    //Filter filter;
    uint8_t debug;
    uint32_t port;
    uint32_t port_send;
    uint32_t port_bind;
    uint8_t broadcast;
    uint32_t baud;
    uint8_t use;
};

int8_t handle_config_file(std::string filename,std::vector <Thread_Config> &configs);
int8_t split_thread_directions(std::vector <Interface_Thread*> &input_threads,
                            std::vector <Interface_Thread*> &output_threads,
                            std::vector <Thread_Config> configs);

#endif // CONFIGURATION_H
