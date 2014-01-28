#ifndef POOLREALISATION_H
#define	POOLREALISATION_H

#include "../../main/task/tasks_pool.h"

class PoolRealisation : public lim_exec::TasksPool {
public:
        PoolRealisation();
        virtual ~PoolRealisation();

        virtual bool PopulateTasks();

protected:
        static logxx::Log cLog;

};

#endif	/* POOLREALISATION_H */

