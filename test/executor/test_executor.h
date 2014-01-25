#ifndef TEST_EXECUTOR_H
#define	TEST_EXECUTOR_H

#include "executor_realisation.h"
#include "../task/pool_realisation.h"

class TestExecutor {
public:
        TestExecutor();
        virtual ~TestExecutor();
        
        bool RunTests();
protected:
        PoolRealisation tasksPool;
        static logxx::Log cLog;

};

#endif	/* TEST_EXECUTOR_H */

