#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>
#include <sys/time.h>

#include "../include/airserver/mavlink.h"


struct Message {
    uint64_t timestamp;
    mavlink_message_t mavlink;
    std::string json;
};

uint64_t getTimestamp();
void applyTimestamp(Message &message);



#endif // MESSAGES_H
