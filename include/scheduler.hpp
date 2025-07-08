#pragma once 
#include<iostream>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<queue>
#include "../include/job.hpp"
#include "../include/worker_pool.hpp"
std::priority_queue<job,std::vector<job>,comparePriority> pq;
std::queue<job>jobQueue;
std::mutex mtx2;

struct comparePriority{
    bool operator()(const job &a,job &b){
        return a.priority < b.priority;
    }
};

void schedule(job currjob){
    std::this_thread::sleep_for(std::chrono::microseconds(currjob.delay_ms));
    std::unique_lock<std::mutex>lock(mtx2);
    std::cout<<"job "<<currjob.id<<" is scheduled"<<std::endl;
    jobQueue.push(currjob);
    cv.notify_one();
    
}

void pq_schedule(job currjob){
    std::this_thread::sleep_for(std::chrono::microseconds(currjob.delay_ms));
    std::unique_lock<std::mutex>lock(mtx2);
    std::cout<<"job "<<currjob.id<<" is scheduled"<<std::endl;
    pq.push(currjob);
    cv.notify_one();
    

}