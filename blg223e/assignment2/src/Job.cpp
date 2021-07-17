#include "Job.h"

const long long inf = 1000000000000000000;

Job::Job(int id, int MI, int start_time) {
    this->id = id;
    this->MI = MI;
    this->start_time = start_time;
    this->finish_time = -1;
}

void Job::execute(int source, int time) {
    this->MI -= source;
    if (this->MI <= 0) {
        this->status = 'F';
        this->finish_time = time;
    }
}

int Job::get_id() {
    return this->id;
}

char Job::get_status() {
    return this->status;
}

void Job::set_status(char status) {
    this->status = status;
}

int Job::get_MI() {
    return this->MI;
}
