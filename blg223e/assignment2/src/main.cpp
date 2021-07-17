#include <iostream>
#include <fstream>
#include <sstream>

#include "Job.h"
#include "Processor.h"

using namespace std;

void simulate(Processor& processor, int first_time, int last_time) {
    for (int i = first_time; i <= last_time; i++)
        processor.execute_jobs();
}

int main(int argc, char* argv[]) {

    if (argc != 2)
        return 1;

    ifstream file (argv[1]);
    if (!file.is_open())
        return 1;

    string line;
    getline(file, line);
    stringstream con (line);

    int first_time, MIPS, MIPS_THRESHOLD;
    con >> first_time >> MIPS >> MIPS_THRESHOLD;
    Processor processor(MIPS, MIPS_THRESHOLD);
    
    while (getline(file, line)) {
        int last_time;
        string command;
        stringstream fcin (line);
        fcin >> last_time >> command; 
        
        if (command == "JOB") {
            simulate(processor, first_time, last_time - 1);
            int id, MI; 
            fcin >> id >>MI;
            Job job(id, MI, last_time);
            processor.add_new_job(job);
        } else if (command == "PRINT") {
            int id; 
            fcin >> id;
            simulate(processor, first_time, last_time);
            processor.print(id);
            
        } else if (command == "PRINTQ") {
            simulate(processor, first_time, last_time);
            processor.printw();
        }  
        first_time = last_time;
    }

    file.close(); 
    return 0;
}
