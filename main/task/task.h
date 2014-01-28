#ifndef LIM_EXEC_TASK_H
#define	LIM_EXEC_TASK_H

#include "../server/server.h"

namespace lim_exec {

        class Task {
        public:
                Task(int id, const std::shared_ptr<Server> &);
                virtual ~Task();

                bool TryOccupyServer();

                const int id;
        protected:
                bool serverOccupied = false;
                std::shared_ptr<Server> server;
                logxx::Log cLog;
        };

        typedef std::unique_ptr<Task> uniqueTask;
        
} //namespace lim_exec

#endif	/* LIM_EXEC_TASK_H */
