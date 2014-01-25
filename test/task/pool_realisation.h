#ifndef POOLREALISATION_H
#define	POOLREALISATION_H

#include "../../main/task/tasks_pool.h"

class PoolRealisation : public TasksPool {
public:
        PoolRealisation();
        virtual ~PoolRealisation();

        virtual bool SingleThreadLoadTasks();

protected:
        static logxx::Log cLog;

};

#endif	/* POOLREALISATION_H */

