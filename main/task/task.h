/* 
 * File:   task.h
 * Author: mexus
 *
 * Created on January 20, 2014, 10:38 AM
 */

#ifndef TASK_H
#define	TASK_H

#include "../server/server.h"

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

#endif	/* TASK_H */

