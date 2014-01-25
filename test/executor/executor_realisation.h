#ifndef EXECUTOR_REALISATION_H
#define	EXECUTOR_REALISATION_H

#include "../../main/executor/executor.h"

class ExecutorRealisation : public Executor {
public:
        ExecutorRealisation(int id);
        virtual ~ExecutorRealisation();
        
protected:
        logxx::Log cLog;

        virtual bool RunTask(const uniqueTask&);
};

#endif	/* EXECUTOR_REALISATION_H */

