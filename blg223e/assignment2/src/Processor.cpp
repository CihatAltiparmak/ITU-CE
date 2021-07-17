#include <iostream>

#include "Job.h"
#include "Processor.h"

const long long inf = 1000000000000000000;
using namespace std;

Processor::Processor(int MIPS, int MIPS_THRESHOLD)
{
    this->MIPS = MIPS;
    this->MIPS_THRESHOLD = MIPS_THRESHOLD;
    this->JOB_PER_SEC
        = (MIPS / MIPS_THRESHOLD) - (MIPS % MIPS_THRESHOLD == 0);
    this->running_job_num = 0;
    this->time = 0;
}

void Processor::execute_jobs()
{
    this->add_from_future();
    this->accept_new_jobs();
    int source;
    if (this->running_job_num)
        source = this->MIPS / this->running_job_num;
    else
        source = 0;
    for (Job& job : this->processed_jobs) {
        if (job.get_status() == 'F')
            continue;

        job.execute(source, time);
        job.start_time = min(job.start_time, (long long)this->time);
        if (job.get_status() == 'F')
            this->running_job_num -= 1;
    }
    
    this->time += 1;
}

void Processor::accept_new_jobs()
{
    while (!this->waiting_jobs.empty()) {
        if (this->running_job_num >= JOB_PER_SEC)
            break;
        Job job = this->waiting_jobs.front();
		job.set_status('R');
        job.start_time = inf;
        this->processed_jobs.push_back(job);
        this->running_job_num += 1;
        this->waiting_jobs.pop();
    }
}

void Processor::add_new_job(Job job)
{
    this->future_jobs.push(job);
}

void Processor::add_from_future()
{
    while (!this->future_jobs.empty()) {
        Job job = this->future_jobs.front();
        if (job.start_time >= this->time)
            return;
        job.set_status('W');
        this->waiting_jobs.push(job);
        this->future_jobs.pop();
    }
}

void Processor::print(int id)
{
    for (Job job : this->processed_jobs) {
        if (job.get_id() == id) {
            cout << job.get_status() << " "
                 << job.start_time - 1<< " "
                 << job.finish_time << " ";
            return;
        }
    }
    cout << "W -1 -1 ";
}

void Processor::printw()
{
    cout << "WQ ";
    int size = this->waiting_jobs.size();
    for (int i = 0; i < size; i++) {
        Job job = this->waiting_jobs.front();
        cout << job.get_id() << " ";
        this->waiting_jobs.push(job);
        this->waiting_jobs.pop();
    }
}
