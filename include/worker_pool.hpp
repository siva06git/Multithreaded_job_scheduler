#pragma once 
#include<iostream>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<queue>
#include "../include/job.hpp"
#include<thread>
#include "../include/scheduler.hpp"
#include "../main.cpp"
void worker_thread(int threadNo){
    while(true){
    job newJob ={0,0,0};
    {
    std::lock_guard<std::mutex> lock(mtx);
    if(!jobQueue.empty())
    newJob = jobQueue.front();
    jobQueue.pop();
    }
    std::cout<<"thread "<<threadNo<<" has been assigned to"<<newJob.id<<std::endl;
    
        std::cout<<"thread "<<threadNo<<" is doing the job "<<newJob.id<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(newJob.duration_ms));
        std::cout<<"thread "<<threadNo<<" has finished doing the job "<<newJob.id<<std::endl;
    }
    

}