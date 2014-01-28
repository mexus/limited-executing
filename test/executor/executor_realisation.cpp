#include "executor_realisation.h"

using namespace lim_exec;

ExecutorRealisation::ExecutorRealisation(int id, TasksPool & pool) : Executor(id, pool), cLog(Executor::cLog, "ExecutorRealisation") {
}

ExecutorRealisation::~ExecutorRealisation() {
}

bool ExecutorRealisation::RunTask(const uniqueTask& t) {
        D_LOG("RunTask");
        log(logxx::info) << "Launching task #" << t->id << logxx::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        bool res = t->id > 1;
        log(logxx::info) << "Returning " << std::boolalpha << res << logxx::endl;
        return res;
}

