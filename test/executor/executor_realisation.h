#ifndef EXECUTOR_REALISATION_H
#define	EXECUTOR_REALISATION_H

#include "../../main/executor/executor.h"

class ExecutorRealisation : public lim_exec::Executor {
public:
        ExecutorRealisation(int id, lim_exec::TasksPool &);
        virtual ~ExecutorRealisation();
        
protected:
        logxx::Log cLog;

        virtual bool RunTask(const lim_exec::uniqueTask&);
};

#endif	/* EXECUTOR_REALISATION_H */

