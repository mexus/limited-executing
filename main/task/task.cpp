/* 
 * File:   task.cpp
 * Author: mexus
 * 
 * Created on January 20, 2014, 10:38 AM
 */

#include "task.h"

Task::Task(int id, const std::shared_ptr<Server>& s) : id(id), server(s), cLog("Task #" + std::to_string(id)) {
}

Task::~Task() {
        S_LOG("~Task");
        if (serverOccupied){
                if (server)
                        server->Release();
                else
                        log(logxx::debug) << "No server specified for a task" << logxx::endl;
        }

}

bool Task::TryOccupyServer() {
        S_LOG("TryOccupyServer");
        if (serverOccupied){
                log(logxx::warning) << "Task already occupies a server" << logxx::endl;
                return false;
        } else {
                if (server) {
                        serverOccupied = server->TryOccupy();
                        return serverOccupied;
                } else {
                        log(logxx::warning) << "No server specified for a task" << logxx::endl;
                        return false;
                }
        }
}

