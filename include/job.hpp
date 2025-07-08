//defining job structure
#pragma once
#ifndef JOB_HPP
#define JOB_HPP

#include<string>
#include<chrono>

struct job{
    int id;
    int duration_ms; // duration of the job in milliseconds
    int delay_ms;   //delay from simulation start
    int priority;
    job(int id, int duration, int delay)
        : id(id), duration_ms(duration), delay_ms(delay),priority(priority){}
};

#endif
