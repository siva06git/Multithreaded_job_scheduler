#pragma once 
#include<iostream>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<queue>
#include "../include/job.hpp"
#include "../src/job.cpp"

std::queue<job>jobQueue;
std::mutex mtx2;

void schedule(job currjob){
    std::this_thread::sleep_for(std::chrono::microseconds(currjob.delay_ms));

    std::unique_lock<std::mutex>lock(mtx2);
    std::cout<<"job "<<currjob.id<<" is scheduled"<<std::endl;
    jobQueue.push(currjob);
    cv.notify_one();
}