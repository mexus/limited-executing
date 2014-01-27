#ifndef TEST_EXECUTOR_H
#define	TEST_EXECUTOR_H

#include "../test_fw.h"
#include "executor_realisation.h"
#include "../task/pool_realisation.h"

class TestExecutor : public TestFW {
public:
        TestExecutor();
        virtual ~TestExecutor();
        
protected:
        static logxx::Log cLog;

        virtual bool Tests();

};

#endif	/* TEST_EXECUTOR_H */

