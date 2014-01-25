#ifndef SERVER_H
#define	SERVER_H

#include <mutex>
#include "../logxx/logxx.h"

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

#endif	/* SERVER_H */

