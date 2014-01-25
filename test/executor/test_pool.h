#ifndef TEST_EXECUTORS_POOL_H
#define	TEST_EXECUTORS_POOL_H

#include "executor_realisation.h"
#include "../task/pool_realisation.h"
#include "../../main/executor/executors_pool.h"

class TestExecutorsPool {
public:
        TestExecutorsPool();
        virtual ~TestExecutorsPool();
        
        bool RunTests();
protected:
        static logxx::Log cLog;
};

#endif	/* TEST_EXECUTORS_POOL_H */

