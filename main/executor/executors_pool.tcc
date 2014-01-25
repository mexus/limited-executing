#include "executors_pool.h"

#ifndef EXECUTORS_POOL_TCC
#define	EXECUTORS_POOL_TCC

#include <type_traits>

template<class ExecutorT, class ...Args>
bool ExecutorsPool::CreateExecutors(size_t count, TasksPool & pool, Args&& ...args){
        static_assert(std::is_base_of<Executor, ExecutorT>::value, "ExecutorT should be derived from an Executor");
        if (executors.empty()){
                for (int i = 0; i < count; ++i){
                        ExecutorPtr executor(new ExecutorT(i, pool, args...));
                        executors.push_back(std::move(executor));
                }
                return true;
        } else
                throw std::logic_error("Can't create executors because they already exists");
}

#endif  //EXECUTORS_POOL_TCC