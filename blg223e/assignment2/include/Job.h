#ifndef _JOB_H_
#define _JOB_H_

class Job {

public:
    void execute(int, int);
    int get_id();
    char get_status();
    void set_status(char);
    int get_MI();
    
    long long start_time = -1;
    long long finish_time = -1;
    
    Job(int, int, int);
    
private:
    int MI;
    int id; 
    char status = 'W';
};

#endif
