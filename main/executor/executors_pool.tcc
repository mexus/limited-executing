#ifndef EXECUTORS_POOL_TCC
#define	EXECUTORS_POOL_TCC

#include "executors_pool.h"
#include <type_traits>

namespace lim_exec {


        template<class ExecutorT, class ...Args>
        bool ExecutorsPool::CreateExecutors(size_t count, TasksPool & pool, Args&& ...args){
                static_assert(std::is_base_of<Executor, ExecutorT>::value, "ExecutorT should be derived from an Executor");
                if (executors.empty()){
                        for (size_t i = 0; i < count; ++i){
                                ExecutorPtr executor(new ExecutorT(i, pool, args...));
                                executors.push_back(std::move(executor));
                        }
                        return true;
                } else
                        throw std::logic_error("Can't create executors because they already exists");
        }
        
} //namespace lim_exec

#endif  //EXECUTORS_POOL_TCC
