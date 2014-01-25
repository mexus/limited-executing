#ifndef TASKS_POOL_H
#define	TASKS_POOL_H

#include "../logxx/logxx.h"
#include "task.h"
#include <vector>

class TasksPool {
public:
        TasksPool();
        virtual ~TasksPool();
        
        uniqueTask GetTask();
        bool LoadTasks();
        bool IsEmpty();
        
protected:
        static logxx::Log cLog;
        std::vector<uniqueTask> scheduledTasks;
        std::mutex dataLock;
        
        virtual bool PopulateTasks() = 0;
};

#endif	/* TASKS_POOL_H */

