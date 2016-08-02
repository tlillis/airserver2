#include "../include/messages.h"

uint64_t getTimestamp() { // Microseconds
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

void applyTimestamp(Message &message) {
    message.timestamp = getTimestamp();
}
