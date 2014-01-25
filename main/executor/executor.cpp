#include "executor.h"
#include <chrono>

const std::time_t Executor::waitOnNullTask;
const std::time_t Executor::waitOnEndTask;

Executor::Executor(int id) : Thread(id), cLog("Executor #" + std::to_string(id)) {
}

Executor::~Executor() {
}

void Executor::SetTasksPool(TasksPool& p) {
        tasksPool = &p;
}

void Executor::Run() {
        Thread::Run();
        D_LOG("Run");
        while (!interrupted){
                auto task = tasksPool->GetTask();
                if (task){
			// cppcheck-suppress constStatement
			log(logxx::notice) << "Starting task #" << task->id << logxx::endl; 
                        bool res = RunTask(task);
                        auto &s = log(logxx::notice) << "Task #" << task->id << " ";
                        if (res)
                                s << "successfully done";
                        else
                                s << "failed";
                        s << logxx::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(waitOnEndTask));
                } else
                        std::this_thread::sleep_for(std::chrono::seconds(waitOnNullTask));
        }
}


