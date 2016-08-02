/**
 *                    Airserver2
 * 
 * Research and Engineering Center for Unmanned Vehicles
 * 
 * Authors: Tom Lillis
 * 
 * Purpose: Data congregation software with flexible
 *          formats and interfaces.
 * 
 **/

#include "../include/configuration.h"
#include "../include/helpers.h"
 
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Starting Airserver2..." << endl << endl;
    
    signal(SIGINT, intHandler); // For killing program
    if(checkArgs(argc,argv)) return 0;

    // Handle the file configs
    vector <Thread_Config> configs;
    uint32_t interface_number = handle_config_file(argv[1],configs);
    cout << "GOT " << interface_number 
         <<" INTERFACE CONFIGURATIONS" 
         << endl << endl;
    
    // Split into input and output vectors
    vector <Interface_Thread> input_threads;
    vector <Interface_Thread> output_threads;
    split_thread_directions(input_threads,output_threads,configs);
    
    // start threads
    
    
    return 0;
}
