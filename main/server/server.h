#ifndef LIM_EXEC_SERVER_H
#define	LIM_EXEC_SERVER_H

#include <mutex>
#include "../logxx/logxx.h"

namespace lim_exec {

        class Server {
        public:
                Server(int id, int limit);
                virtual ~Server();

                void UpdateLimit(int newLimit);

                bool TryOccupy();
                void Release();

                int InUse();

                const int id;
        private:
                int limit;
                int inUse;
                std::mutex access;
                logxx::Log cLog;
        };
        
} //namespace lim_exec

#endif	/* LIM_EXEC_SERVER_H */

