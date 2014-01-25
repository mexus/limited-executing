/* 
 * File:   TestTask.h
 * Author: mexus
 *
 * Created on January 24, 2014, 12:28 PM
 */

#ifndef TESTTASK_H
#define	TESTTASK_H

#include "../../main/task/task.h"

class TestTask {
public:
        TestTask();
        virtual ~TestTask();
        
        bool RunTests();
private:
        static logxx::Log cLog;

};

#endif	/* TESTTASK_H */

