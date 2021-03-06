#ifndef LIM_EXEC_EXECUTORS_POOL_H
#define	LIM_EXEC_EXECUTORS_POOL_H

#include "../logxx/logxx.h"
#include "executor.h"

namespace lim_exec {

        class ExecutorsPool {
        public:
                ExecutorsPool();
                virtual ~ExecutorsPool();

                template<class ExecutorT, class ...Args>
                bool CreateExecutors(size_t count, TasksPool &, Args&& ...args);

                bool LaunchExecutors();
                void Interrupt(bool andJoin = false);
                void WaitForExecutors();

        protected:
                typedef std::unique_ptr<Executor> ExecutorPtr;
                std::vector<ExecutorPtr> executors;
                static logxx::Log cLog;

        };

} //namespace lim_exec

#include "executors_pool.tcc"

#endif	/* LIM_EXEC_EXECUTORS_POOL_H */

