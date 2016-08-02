#include "../include/helpers.h"

pid_t pid = 0;

using namespace std;

uint8_t checkArgs(int argc, char* argv[]) {
    if(argc < 2 || argc > 3) { // Check arguments
        cout << "Invalid number of arguments" << endl;
        printUsage();
        return -1;
    }
    
    if(argc == 3 && (strcmp(argv[2],"sitl") || strcmp(argv[2],"Sitl") || strcmp(argv[2],"SITL"))) {
        startSITL();
    }
    return 0;
}

void intHandler(int dummy) {
    
    if(pid > 0) {
        exit(0);
    }
    if(pid == 0) {
        cout << "End!" << endl;
        exit(0);
    }
    exit(0);
}

void printUsage() {
    cout << "Usage: " << endl;
    cout << "  ./Airserver <config file> <sitl>" << endl;
    cout << "Examples: " << endl;
    cout << "  ./Airserver config.txt" << endl;
    cout << "  ./Airserver config.txt sitl" << endl;
}

void startSITL() {
    cout << "Setting up SITL connection..." << endl;
    pid = fork();
    if (pid == 0) {
        //Not calling to system() because system() forks a process and won't quit with SIGINT
        execl("/bin/sh"
            , "sh"
            ,"-c"
            , "xterm -e \"socat -d -d UDP-LISTEN:14550 pty,raw,echo=0,link=/tmp/ttyV0\""
            ,(char *) 0);
        return;
    }
    if (pid > 0) {
        sleep(1); // Wait for SITL to be setup. May need to be longer
    }
    else {
        cout << "fork() failed!" << endl;
        return;
    }
}
