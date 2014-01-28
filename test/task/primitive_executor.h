#ifndef PRIMITIVE_EXECUTOR_H
#define	PRIMITIVE_EXECUTOR_H

#include "../../main/task/task.h"
#include "../../main/threadxx/threadxx.h"

class PrimitiveExecutor : public Thread {
public:
        PrimitiveExecutor(lim_exec::uniqueTask &&task);
        virtual ~PrimitiveExecutor();
protected:
        virtual void Run();
        logxx::Log cLog;
private:
        lim_exec::uniqueTask task;

};

#endif	/* PRIMITIVE_EXECUTOR_H */

