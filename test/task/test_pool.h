#ifndef TESTPOOL_H
#define	TESTPOOL_H

#include "../test_fw.h"
#include "../../main/logxx/logxx.h"
#include "pool_realisation.h"

class TestPool : public TestFW {
public:
        TestPool();
        virtual ~TestPool();
        
private:
        static logxx::Log cLog;
        
        PoolRealisation pool;

        virtual bool Tests();

        bool LoadTasks();
        bool RunTasks();
        
        static void ExecuteTask(uniqueTask &&task);
        
};

#endif	/* TESTPOOL_H */

