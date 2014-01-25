/* 
 * File:   TestPool.cpp
 * Author: mexus
 * 
 * Created on January 24, 2014, 12:50 PM
 */

#include "test_pool.h"
#include <atomic>
#include <thread>
#include "primitive_executor.h"

logxx::Log TestPool::cLog("TestPool");

TestPool::TestPool() {
}

TestPool::~TestPool() {
}

bool TestPool::LoadTasks() {
        S_LOG("LoadTasks");
        if (!pool.LoadTasks()){
                log(logxx::error) << "Can't load tasks to pool" << logxx::endl;
                return false;
        } else if (pool.IsEmpty()){
                log(logxx::error) << "Pool is empty" << logxx::endl;
                return false;
        } else
                return true;
}


bool TestPool::RunTasks() {
        D_LOG("RunTasks");
        
        try {
        
                std::atomic_bool interrupted(false), done(false);
                log(logxx::debug) << "Form vector of executors" << logxx::endl;

                std::vector<std::shared_ptr<PrimitiveExecutor> > executors;

                log(logxx::debug) << "Creating timeout-check tread" << logxx::endl;
                auto thread = std::thread([&interrupted, &done, &log]{
                        log(logxx::info, "std::thread") << "Timeout set for " << "120" << "s" << logxx::endl;
                        auto start = std::chrono::system_clock::now();
                        auto timeOut = std::chrono::minutes(2);
                        while (!done.load()){
                                auto now = std::chrono::system_clock::now();
                                if ( (now - start) > timeOut){
                                        interrupted.store(true);
                                        log(logxx::warning, "std::thread") << "Waiting time exceeded" << logxx::endl;
                                        return ;
                                } else
                                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        }
                });
                while (!interrupted.load() && !pool.IsEmpty()){
                        auto task = pool.GetTask();
                        if (task){
                                log(logxx::info) << "Launching executor for task " << task->id << logxx::endl;
                                auto exec = std::make_shared<PrimitiveExecutor>(std::move(task));
                                executors.push_back(exec);
                                exec->Start();
                        } else
                                log(logxx::info) << "No tasks obtained" << logxx::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
                done.store(true);
                thread.join();
                
                if (!pool.IsEmpty()){
                        log(logxx::error) << "Pool should be empty by now" << logxx::endl;
                        return false;
                }
                return true;
        } catch (const std::exception &e){
                log(logxx::error) << "Catched an exception: " << e.what() << logxx::endl;
                return false;
        }
}

bool TestPool::RunTests() {
        S_LOG("RunTests");
        log(logxx::info) << "Running tests" << logxx::endl;
        
        //return LoadTasks() ;//&& RunTasks();
        return LoadTasks() && RunTasks();
}
