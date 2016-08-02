#ifndef HELPERS_H
#define HELPERS_H

#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

uint8_t checkArgs(int argc, char* argv[]);
void intHandler(int dummy);
void printUsage();
void startSITL();

#endif // HELPERS_H
