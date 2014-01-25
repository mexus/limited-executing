#include "test_task.h"

logxx::Log TestTask::cLog("TestTask");

TestTask::TestTask() {
}

TestTask::~TestTask() {
}

bool TestTask::RunTests() {
        S_LOG("RunTests");
        log(logxx::info) << "Running tests" << logxx::endl;
        
        std::shared_ptr<Server> s1(new Server(2, 1));
        std::shared_ptr<Task> t1(new Task(1, s1));
        
        if (!t1->TryOccupyServer()){
                log(logxx::error) << "Server should be free" << logxx::endl;
                return false;
        }
        if (t1->TryOccupyServer()){
                log(logxx::error) << "Task can't occupy server for a second time" << logxx::endl;
                return false;
        }
        t1.reset();
        
        if (s1->InUse() != 0){
                log(logxx::error) << "Server should be completely free by now" << logxx::endl;
                return false;
        }
        
        t1 = std::make_shared<Task>(1, s1);
        s1->TryOccupy();
        
        if (t1->TryOccupyServer()){
                log(logxx::error) << "Server should not be free" << logxx::endl;
                return false;
        }
        
        
        return true;
}


