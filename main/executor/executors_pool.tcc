#include "executors_pool.h"

#ifndef EXECUTORS_POOL_TCC
#define	EXECUTORS_POOL_TCC

#include <type_traits>

template<class ExecutorT>
ExecutorsPool::ExecutorsPool(int executorsCnt){
        static_assert(std::is_base_of<Executor, ExecutorT>::value, "ExecutorT should be derived from an Executor");
        for (int i = 0; i < executorsCnt; ++i)
                executors.emplace_back(new ExecutorT());
}

#endif  //EXECUTORS_POOL_TCC