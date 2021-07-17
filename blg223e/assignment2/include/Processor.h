#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <queue>
#include <vector>

#include "Job.h"

using namespace std;

class Processor {
public:
    void execute_jobs();
    void accept_new_jobs();
    void add_new_job(Job);
    void add_from_future();
    void print(int id);
    void printw();
    Processor(int, int);

private:
    int MIPS;
    int MIPS_THRESHOLD;
    int JOB_PER_SEC;
    int running_job_num;
    int time;
    vector<Job> processed_jobs;
    queue<Job> waiting_jobs;
    queue<Job> future_jobs;
};

#endif
