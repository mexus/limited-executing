#ifndef TESTTASK_H
#define	TESTTASK_H

#include "../test_fw.h"
#include "../../main/task/task.h"

class TestTask : public TestFW {
public:
        TestTask();
        virtual ~TestTask();
        
private:
        static logxx::Log cLog;

        virtual bool Tests();

};

#endif	/* TESTTASK_H */

