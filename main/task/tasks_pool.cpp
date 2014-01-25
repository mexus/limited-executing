#include "tasks_pool.h"

logxx::Log TasksPool::cLog("TasksPool");

TasksPool::TasksPool() {
}

TasksPool::~TasksPool() {
}

uniqueTask TasksPool::GetTask() {
        std::lock_guard<std::mutex> lg(dataLock);
//        for (auto it = scheduledTasks.begin(); it != scheduledTasks.end(); ++it){
//                uniqueTask &task = *it;
//                if (!task){
//                        throw std::logic_error("Found nullptr task at " + std::to_string(it - scheduledTasks.begin()));
//                }
//        }
        for (auto it = scheduledTasks.begin(); it != scheduledTasks.end(); ++it){
                if ((*it)->TryOccupyServer()){
                        uniqueTask task = std::move(*it);
                        scheduledTasks.erase(it);
                        return std::move(task);
                }
        }
        return uniqueTask();
}

bool TasksPool::LoadTasks() {
        std::lock_guard<std::mutex> lg(dataLock);
        return PopulateTasks();
}

bool TasksPool::IsEmpty() {
        std::lock_guard<std::mutex> lg(dataLock);
        return scheduledTasks.empty();
}

