#ifndef EXECUTOR_H
#define	EXECUTOR_H

#include "../logxx/logxx.h"
#include "../task/tasks_pool.h"
#include "../threadxx/threadxx.h"

namespace lim_exec {

        class Executor : public Thread {
        public:
                Executor(int id, TasksPool &);
                virtual ~Executor();
        protected:
        // cppcheck-suppress duplInheritedMember
                logxx::Log cLog; 
                TasksPool& tasksPool;
                static const std::time_t waitOnNullTask = 15;
                static const std::time_t waitOnEndTask = 2;

                virtual void Run();
                virtual bool RunTask(const uniqueTask &) = 0;
        };
} //namespace lim_exec

#endif	/* EXECUTOR_H */

