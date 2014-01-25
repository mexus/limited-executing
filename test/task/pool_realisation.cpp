/* 
 * File:   PoolRealisation.cpp
 * Author: mexus
 * 
 * Created on January 24, 2014, 2:47 PM
 */

#include "pool_realisation.h"

logxx::Log PoolRealisation::cLog(TasksPool::cLog, "PoolRealisation");

PoolRealisation::PoolRealisation() {
}

PoolRealisation::~PoolRealisation() {
}

bool PoolRealisation::SingleThreadLoadTasks() {
        S_LOG("LoadTasks");
        auto server1 = std::make_shared<Server>(1, 2);
        auto server2 = std::make_shared<Server>(2, 1);
        auto server3 = std::make_shared<Server>(3, 5);
        
        scheduledTasks.emplace_back(new Task(1, server1));
        scheduledTasks.emplace_back(new Task(2, server1));
        scheduledTasks.emplace_back(new Task(3, server1));
        
        scheduledTasks.emplace_back(new Task(4, server2));
        scheduledTasks.emplace_back(new Task(5, server2));
        
        scheduledTasks.emplace_back(new Task(6, server3));
        
        return true;
}
