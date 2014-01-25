#ifndef EXECUTORS_POOL_H
#define	EXECUTORS_POOL_H

#include "../logxx/logxx.h"
#include "executor.h"

class ExecutorsPool {
public:
        template<class ExecutorT>
        ExecutorsPool(int executors);
        virtual ~ExecutorsPool();
        
        void SetTasksPool(TasksPool &);
        bool LaunchExecutors();
        void Interrupt(bool andJoin = false);
        void WaitForExecutors();
        
protected:
        typedef std::unique_ptr<Executor> ExecutorPtr;
        std::vector<ExecutorPtr> executors;
        static logxx::Log cLog;

};

#include "executors_pool.tcc"

#endif	/* EXECUTORS_POOL_H */

