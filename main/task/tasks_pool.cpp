#include "tasks_pool.h"

namespace lim_exec {

        logxx::Log TasksPool::cLog("TasksPool");

        TasksPool::TasksPool() {
        }

        TasksPool::~TasksPool() {
        }

	void TasksPool::GetTaskPrologue(){
	}

        uniqueTask TasksPool::GetTask() {
		S_LOG("GetTask");
                std::lock_guard<std::mutex> lg(dataLock);
		GetTaskPrologue();
                for (auto it = scheduledTasks.begin(); it != scheduledTasks.end(); ++it){
                        if ((*it)->TryOccupyServer()){
                                uniqueTask task = std::move(*it);
                                scheduledTasks.erase(it);
                                return std::move(task);
                        }
                }
                return uniqueTask();
        }

        void TasksPool::TaskDone(uniqueTask&& task, bool ok) {
                S_LOG("TaskDone");
                std::lock_guard<std::mutex> lg(dataLock);
                auto &s = log(logxx::notice) << "Task #" << task->id << " ";
                if (ok)
                        s << "successfully done";
                else
                        s << "failed";
                s << logxx::endl;
        }

        bool TasksPool::LoadTasks() {
                std::lock_guard<std::mutex> lg(dataLock);
                return PopulateTasks();
        }

        bool TasksPool::IsEmpty() {
                std::lock_guard<std::mutex> lg(dataLock);
                return scheduledTasks.empty();
        }
        
} //namespace lim_exec
