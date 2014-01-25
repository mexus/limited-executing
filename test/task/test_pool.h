#ifndef TESTPOOL_H
#define	TESTPOOL_H

#include "../../main/logxx/logxx.h"
#include "pool_realisation.h"

class TestPool {
public:
        TestPool();
        virtual ~TestPool();
        
        bool RunTests();
private:
        static logxx::Log cLog;
        
        PoolRealisation pool;
        
        bool LoadTasks();
        bool RunTasks();
        
        static void ExecuteTask(uniqueTask &&task);
        
};

#endif	/* TESTPOOL_H */

