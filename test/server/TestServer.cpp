/* 
 * File:   TestServer.cpp
 * Author: mexus
 * 
 * Created on January 24, 2014, 12:13 PM
 */

#include "TestServer.h"

logxx::Log TestServer::cLog("TestServer");

TestServer::TestServer() {
}

TestServer::~TestServer() {
}

bool TestServer::RunTests() {
        S_LOG("RunTests");
        log(logxx::info) << "Running tests" << logxx::endl;
        int limit(10);
        Server s(1, limit);
        for (int i = 0; i < limit; ++i){
                if (!s.TryOccupy()){
                        log(logxx::error) << "Can't occupy server: " << i+1 << "/" << limit+1 << logxx::endl;
                        return false;
                }
        }
        if (s.TryOccupy()){
                log(logxx::error) << "Server shouldn't be free at the moment" << logxx::endl;
                return false;
        }
        for (int i = 0; i < limit; ++i)
                s.Release();
        if (s.InUse() != 0){
                log(logxx::error) << "Server should be completely free by now" << logxx::endl;
                return false;
        }
        log(logxx::info) << "Testing 'negative warning' (two times)" << logxx::endl;
        s.Release();
        s.Release();
        if (s.InUse() != 0){
                log(logxx::error) << "Server should be completely free by now" << logxx::endl;
                return false;
        }
        return true;
}

