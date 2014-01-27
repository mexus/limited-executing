#ifndef TEST_EXECUTORS_POOL_H
#define	TEST_EXECUTORS_POOL_H

#include "../test_fw.h"
#include "executor_realisation.h"
#include "../task/pool_realisation.h"
#include "../../main/executor/executors_pool.h"

class TestExecutorsPool : public TestFW {
public:
        TestExecutorsPool();
        virtual ~TestExecutorsPool();
        
protected:
        static logxx::Log cLog;

        virtual bool Tests();

};

#endif	/* TEST_EXECUTORS_POOL_H */

