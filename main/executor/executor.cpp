#include "executor.h"
#include <chrono>

namespace lim_exec {

        const std::time_t Executor::waitOnNullTask;
        const std::time_t Executor::waitOnEndTask;

        Executor::Executor(int id, TasksPool &tasksPool) : Thread(id), cLog("Executor #" + std::to_string(id)), tasksPool(tasksPool) {
        }

        Executor::~Executor() {
        }

        void Executor::Run() {
                Thread::Run();
                D_LOG("Run");
                while (!interrupted){
                        auto task = tasksPool.GetTask();
                        if (task){
                                // cppcheck-suppress constStatement
                                log(logxx::notice) << "Starting task #" << task->id << logxx::endl; 
                                bool res = RunTask(task);
                                tasksPool.TaskDone(std::move(task), res);
                                std::this_thread::sleep_for(std::chrono::seconds(waitOnEndTask));
                        } else
                                std::this_thread::sleep_for(std::chrono::seconds(waitOnNullTask));
                }
        }

} //namespace lim_exec
