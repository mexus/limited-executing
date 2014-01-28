#ifndef LIM_EXEC_TASKS_POOL_H
#define	LIM_EXEC_TASKS_POOL_H

#include "../logxx/logxx.h"
#include "task.h"
#include <vector>

namespace lim_exec {

        class TasksPool {
        public:
                TasksPool();
                virtual ~TasksPool();

                uniqueTask GetTask();
                void TaskDone(uniqueTask &&, bool ok);
                bool LoadTasks();
                bool IsEmpty();

        protected:
                static logxx::Log cLog;
                std::vector<uniqueTask> scheduledTasks;
                std::mutex dataLock;

		virtual void GetTaskPrologue();
                virtual bool PopulateTasks() = 0;
        };
        
} //namespace lim_exec

#endif	/* LIM_EXEC_TASKS_POOL_H */

