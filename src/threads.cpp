#include "../include/threads.h"
#include "../include/configuration.h"
#include "../include/serial_port.h"
#include "../include/conversions.h"

uint8_t Interface_Thread::try_lock_input() {
    return pthread_mutex_trylock(&lock_input);
}

uint8_t Interface_Thread::unlock_input() {
    return pthread_mutex_unlock(&lock_input);
}

uint8_t Interface_Thread::try_lock_output() {
    return pthread_mutex_trylock(&lock_output);
}

uint8_t Interface_Thread::unlock_output() {
    return pthread_mutex_unlock(&lock_output);
}

uint8_t Interface_Thread::try_pop_ouput(Message &message) {
    if(try_lock_output()){
        if(!output_q.empty()) {
            message = output_q.front();
            output_q.pop();
            unlock_output();
            return 0;
        }
        unlock_output();
        return 1;
    }
    return 2;
}

uint8_t Interface_Thread::try_push_ouput(Message message) {
    if(try_lock_output()){
        output_q.push(message);
        unlock_output();
        return 0;
    }
    return 2;
}

uint8_t Interface_Thread::try_pop_input(Message &message) {
    if(try_lock_input()){
        if(!input_q.empty()) {
            message = input_q.front();
            input_q.pop();
            unlock_input();
            return 0;
        }
        unlock_input();
        return 1;
    }
    return 2;
}

uint8_t Interface_Thread::try_push_input(Message message) {
    if(try_lock_input()){
        input_q.push(message);
        unlock_input();
        return 0;
    }
    return 2;
}

uint8_t Interface_Thread::try_pop(Message &message) {
    return try_pop_input(message);
}

uint8_t Interface_Thread::try_push(Message message) {
    return try_push_ouput(message);
}

UDP_Thread::UDP_Thread(std::string address, uint32_t port, uint8_t format, uint8_t debug, uint16_t thread_number){
    _address = address;
    _port = port;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void UDP_Thread::thread_start() {
    pthread_create(&thread, NULL, &UDP_Thread::enter_handler, this);
    return;
}

void *UDP_Thread::handler(void) {
    std::cout << "Hello, world! OMG UDP" << std::endl;
    return 0;
}

void *UDP_Thread::enter_handler(void *context) {
    return ((UDP_Thread *)context)->handler();
}

void UDP_Thread::interface_json() {
    //struct sockaddr_in si_me, si_other;
    //int s, i, slen=sizeof(si_other);
    //char buf[BUFLEN];
    
    //if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        //diep("socket");
    
    //memset((char *) &si_me, 0, sizeof(si_me));
    //si_me.sin_family = AF_INET;
    //si_me.sin_port = htons(PORT);
    //si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    //if (bind(s, &si_me, sizeof(si_me))==-1)
        //diep("bind");
    
    //for (i=0; i<NPACK; i++) {
        //if (recvfrom(s, buf, BUFLEN, 0, &si_other, &slen)==-1)            //diep("recvfrom()");
            //printf("Received packet from %s:%d\nData: %s\n\n", 
            //inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
    //}
    
    //close(s);
    return;
}

void UDP_Thread::interface_mavlink() {
    
    return;
}

Serial_Thread::Serial_Thread(std::string port, uint32_t baud, uint8_t format, uint8_t debug, uint16_t thread_number){
    _port = port;
    _baud = baud;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void Serial_Thread::thread_start() {
    pthread_create(&thread, NULL, &Serial_Thread::enter_handler, this);
    return;
}

void Serial_Thread::interface_json() {
    
    return;
}

void Serial_Thread::interface_mavlink() {
    std::cout << "MAVLINK SERIAL THREAD" << std::endl;
    mavlink_message_t message_mavlink;
    char * port = (char*)_port.c_str();
    int count_r = 0;
    int baud = _baud;

    Serial_Port serial_port(port, baud);

    int len = 0;

    //int gotData = 0;

    serial_port.start();
        
    //while(!gotData) {
    //    serial_port.start();
    //    gotData = serial_port.read_message_mavlink(message_mavlink,2);
    //    if(!gotData) {
    //        serial_port.stop();
    //    }
    //}
        
    std::cout << port << " GOT MAVLINK DATA" << std::endl;

    while(1) {
        if (serial_port.status == 1) {
            len = serial_port.read_message_mavlink(message_mavlink,2);
        }
        else {
            break;
        }
        if (len) {
            Message message;
            applyTimestamp(message);
            message.mavlink = message_mavlink;
            mav_to_json(message);
            while(try_push_input(message)) {}
            std::cout << "Got " << count_r << " messages" << std::endl;
            count_r++;
            }
        usleep(100);
    }
    return;
}

void Serial_Thread::interface_vectornav() {
    
    return;
}

void *Serial_Thread::handler(void) {
    std::cout << "Hello, world! Ho man Serial!" << std::endl;
    
    if(_format == JSON) interface_json();
    else if(_format == MAVLINK) interface_mavlink();
    else if(_format == VECTORNAV) interface_vectornav();
    else std::cout << "UNKOWN SERIAL TYPE " << _format << " FOR INTERFACE " << _port << std::endl;
    
    return 0;
}

void *Serial_Thread::enter_handler(void *context) {
    return ((Serial_Thread *)context)->handler();
}

Log_Thread::Log_Thread(std::string file, uint8_t format, uint8_t debug, uint16_t thread_number){
    _file = file;
    _format = format;
    _debug = debug;
    _thread_number = thread_number;
}

void Log_Thread::thread_start() {
    pthread_create(&thread, NULL, &Log_Thread::enter_handler, this);
    return;
}

void *Log_Thread::handler(void) {
    std::cout << "Hello, world! Time for some logging in " << _file << std::endl;
    // Check to make new file
    unsigned int file_tag = 0;
    std::ostringstream oss;

    oss << _file << file_tag << ".txt";
    while (std::ifstream(oss.str().c_str())) { //Check if file already exists
        file_tag++;
        oss.str("");
        oss.clear();
        oss << _file << file_tag << ".txt";
    }

    std::string message;

    // int count = 0;

    FILE* pFile;
    pFile = fopen(oss.str().c_str(), "wb");

    while (1) {
        if (pFile!=NULL) {
            Message message;
            if(!try_pop_ouput(message)) {
                if(fwrite(message.json.c_str(), 1, strlen(message.json.c_str()), pFile)) {
                    fwrite("\n", sizeof(char), 1, pFile);
                    fflush(pFile);
                    //count++;
                }
            }
        }
        //usleep(5000);
    }
    fclose(pFile);
    return 0;
}

void *Log_Thread::enter_handler(void *context) {
    //std::cout << "HEYHYEHYE" << _file << std::endl;
    return ((Log_Thread *)context)->handler();
}

