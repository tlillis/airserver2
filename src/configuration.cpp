#include "../include/configuration.h"
#include <iostream>
#include <ctime>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int8_t handle_config_file(std::string filename,std::vector <Thread_Config> &configs) {
    
    std::ifstream infile(filename.c_str());
    
    std::string line;
    int8_t interface_number = -1;
    
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        string col1,col2;
        iss >> col1 >> col2;
        
        if(col1.length() > 0 && col1[0] != '#') {
                if(col1 == "type") {
                    Thread_Config config;
                    configs.push_back(config);
                    interface_number++;

                    if(col2 == "SERIAL") {
                        configs[interface_number].type = SERIAL;
                    }
                    else if(col2 == "UDP") {
                        configs[interface_number].type = UDP;
                    }
                    else if(col2 == "LOGGING") {
                        configs[interface_number].type = LOGGING;
                    }
                    else {
                        cout << "UKNOWN INTERFACE TYPE=" << col2 << " FOR INTERFACE NUMBER " << static_cast<int16_t>(interface_number) << endl;
                        return 0;
                    }
                }
                else if(col1 == "format") {
                    if(col2 == "MAVLINK") {
                        configs[interface_number].format = MAVLINK;
                    }
                    else if(col2 == "JSON") {
                        configs[interface_number].format = JSON;
                    }
                    else {
                        cout << "UKNOWN FORMAT=" << col2 << " FOR INTERFACE NUMBER " << static_cast<int16_t>(interface_number) << endl;
                    }
                }
                else if(col1 == "direction") {
                    if(col2 == "IN") {
                        configs[interface_number].direction = IN;
                    }
                    else if(col2 == "OUT") {
                        configs[interface_number].direction = OUT;
                    }
                    else {
                        cout << "UKNOWN DIRECTION=" << col2 << " FOR INTERFACE NUMBER " << static_cast<int16_t>(interface_number) << endl;
                    }
                }
                else if(col1 == "interface") {
                    configs[interface_number].interface = col2;
                }
                else if(col1 == "filter") {
                    // TODO handle filter
                }
                else if(col1 ==  "debug") {
                    int debug = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].debug = debug;
                }
                else if(col1 == "port") {
                    int port = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].port = port;
                }
                else if(col1 == "port_send") {
                    int port_send = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].port_send = port_send;
                }
                else if(col1 == "port_bind") {
                    int port_bind = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].port_bind = port_bind;
                }
                else if(col1 == "broadcast") {
                    int broadcast = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].broadcast = broadcast;
                }
                else if(col1 == "baud") {
                    int baud = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].baud = baud;
                }
                else if(col1 == "use:") {
                    int use = strtol(col2.c_str(),NULL,10);
                    configs[interface_number].use = use;
                }
                else {
                }
        }
    }
    return ++interface_number; // increment by 1 so non index count
}

int8_t split_thread_directions(std::vector <Interface_Thread*> &input_threads, 
                            std::vector <Interface_Thread*> &output_threads,
                            std::vector <Thread_Config> configs) {
    for(uint16_t i = 0; i < configs.size(); i++) {
        uint8_t type = configs[i].type;
        uint8_t direction = configs[i].direction;
        Interface_Thread *thread;
        
        switch(type) {
            case UDP: 
            {
                UDP_Thread *udp = new UDP_Thread;
                thread = udp;
                break;
            }
            case SERIAL:
            {
                Serial_Thread *serial = new Serial_Thread;
                thread = serial;
                break;
            }
            case LOGGING:
            {
                Log_Thread *logging = new Log_Thread;
                thread = logging;
                break;
            }
            default:
                cout << "Uknown interface type" << endl;
                return 0;
                break;
        }
        
        if(direction == IN) {
            input_threads.push_back(thread);
        }
        else if(direction == OUT) {
            output_threads.push_back(thread);
        }
        else {
            cout << "Unkown interface direction" << endl;
        }
    }
    return 0;
}
