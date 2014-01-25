#include "test_executor.h"

logxx::Log TestExecutor::cLog("TestExecutor");

TestExecutor::TestExecutor() {
}

TestExecutor::~TestExecutor() {
}

bool TestExecutor::RunTests() {
        S_LOG("RunTests");
        logxx::SetLogLevel(logxx::notice);
        if (!tasksPool.LoadTasks()){
                log(logxx::error) << "Can't load tasks pool" << logxx::endl;
                return false;
        }
        
        auto t1 = std::thread([this]{
                std::this_thread::sleep_for(std::chrono::seconds(40));
                log(logxx::info) << "Populating pool again" << logxx::endl;
                tasksPool.LoadTasks();
        });
        
        ExecutorRealisation ex(0, tasksPool);
        auto t2 = std::thread([this, &ex]{
                std::this_thread::sleep_for(std::chrono::seconds(85));
                log(logxx::info) << "Interrupting executor" << logxx::endl;
                ex.Interrupt();
        });
        
        ex.Start();
        ex.Join();
        t1.join();
        t2.join();
        if (!tasksPool.IsEmpty()){
                log(logxx::error) << "Tasks pool should be empty by now" << logxx::endl;
                return false;
        }
        return true;
}

