#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "serial_port.h"
#include "messages.h"
#include <string>
//#include <sstream>


int mav_to_json(Message &message);

int json_to_mav(char * json_message);

#endif // CONVERSIONS
