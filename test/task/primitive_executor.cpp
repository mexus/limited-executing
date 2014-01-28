#include "primitive_executor.h"

using namespace lim_exec;

PrimitiveExecutor::PrimitiveExecutor(uniqueTask&& task) : Thread(task->id), cLog(Thread::cLog, "PrimitiveExecutor"), task(std::move(task)) {
}

PrimitiveExecutor::~PrimitiveExecutor() {
}

void PrimitiveExecutor::Run() {
        Thread::Run();
        D_LOG("Run");
        uniqueTask task = std::move(this->task);
        if (task){
                log(logxx::info, "Task #" + std::to_string(task->id)) << "Starting task" << logxx::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5 + task->id ));
                log(logxx::info, "Task #" + std::to_string(task->id)) << "Done" << logxx::endl;
        } else {
                log(logxx::error) << "Empty pointer passed!" << logxx::endl;
        }
}

