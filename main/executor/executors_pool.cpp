#include "executors_pool.h"

logxx::Log ExecutorsPool::cLog("ExecutorsPool");

ExecutorsPool::~ExecutorsPool() {
}

void ExecutorsPool::SetTasksPool(TasksPool& p) {
        for (ExecutorPtr &e : executors){
                e->SetTasksPool(p);
        }
}

bool ExecutorsPool::LaunchExecutors() {
        S_LOG("LaunchExecutors");
        auto begin = executors.begin();
        auto end = executors.end();
        for (auto it = begin; it != end; ++it){
                ExecutorPtr& e = *it;
                if (!e->Start()){
                        log(logxx::error) << "Can't launch an executor #" << e->id <<
                                "; interrupting and joining previously launched executors" << logxx::endl;
                        for (auto it2 = begin; it2 != it; ++it2){
                                ExecutorPtr& e = *it2;
                                e->Interrupt();
                                e->Join();
                        }
                        return false;
                }
        }
	// cppcheck-suppress constStatement
        log(logxx::notice) << "Launched " << executors.size() << " executors" << logxx::endl;
        return true;
}

void ExecutorsPool::Interrupt(bool andJoin) {
        for (ExecutorPtr &e : executors)
                e->Interrupt();
        if (andJoin){
                for (ExecutorPtr &e : executors)
                        e->Join();
        }
}

void ExecutorsPool::WaitForExecutors() {
        for (ExecutorPtr &e : executors)
                e->Join();
}


