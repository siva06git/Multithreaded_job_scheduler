#include<iostream>
#include<vector>
#include<thread>
#include<chrono>
#include "include/job.hpp"
#include "src/scheduler.cpp"
#include "src/worker_pool.cpp"
int main(){
    int n ;
    std::cout<<"Number of threads you want to use"<<std::endl;
    std::cin>>n;
    std::vector<std::thread> threads;

    for(int i = 0 ;i<n;i++){
        threads.emplace_back(worker_thread,i+1);
    }

}