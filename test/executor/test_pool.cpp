#include "test_pool.h"

using namespace lim_exec;

logxx::Log TestExecutorsPool::cLog("TestExecutorsPool");

TestExecutorsPool::TestExecutorsPool() : TestFW("executors-pool") {
}

TestExecutorsPool::~TestExecutorsPool() {
}

bool TestExecutorsPool::Tests() {
        S_LOG("RunTests");
        
        PoolRealisation tasksPool;
        if (!tasksPool.LoadTasks()){
                log(logxx::error) << "Can't load tasks" << logxx::endl;
                return false;
        }
        ExecutorsPool executorsPool;
        if (!executorsPool.CreateExecutors<ExecutorRealisation>(3, tasksPool)){
                log(logxx::error) << "Can't create executors" << logxx::endl;
                return false;
        }
        
        try {
                executorsPool.CreateExecutors<ExecutorRealisation>(10, tasksPool);
                log(logxx::error) << "An exception should be raised" << logxx::endl;
                return false;
        } catch (const std::logic_error& e){
                log(logxx::info) << "Catched an exception: " << e.what() << logxx::endl;
        }
        
        if (!executorsPool.LaunchExecutors()){
                log(logxx::error) << "Can't launch executors" << logxx::endl;
                return false;
        }
        
        {
                auto thread = std::thread([&executorsPool]{
                        std::this_thread::sleep_for(std::chrono::seconds(20));
                        executorsPool.Interrupt();
                });
                thread.join();
        }
        executorsPool.WaitForExecutors();
        
        return true;
}

