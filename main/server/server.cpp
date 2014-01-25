#include "server.h"

Server::Server(int id, int limit) : id(id), limit(limit), inUse(0), cLog("Server #" + std::to_string(id)) {
}

Server::~Server() {
}

void Server::UpdateLimit(int newLimit) {
        limit = newLimit;
}

bool Server::TryOccupy() {
        std::lock_guard<std::mutex> lock(access);
        D_LOG("TryOccupy");
        if (inUse < limit){
                ++inUse;
                log(logxx::debug) << "Occupying server" << logxx::endl;
                return true;
        } else {
                log(logxx::debug) << "Server is fully occupied" << logxx::endl;
                return false;
        }
}

void Server::Release() {
        std::lock_guard<std::mutex> lock(access);
        D_LOG("Release");
        log(logxx::debug) << "Releasing server" << logxx::endl;
        inUse -= 1;
        if (inUse < 0){
                log(logxx::warning) << "Strange thins happens.. server is in use negative times (" << inUse << ")" << logxx::endl;
                inUse = 0;
        }
}

int Server::InUse(){
        std::lock_guard<std::mutex> lock(access);
        return inUse;
}

