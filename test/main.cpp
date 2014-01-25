#include "../main/logxx/logxx.h"
#include "server/test_server.h"
#include "task/test_task.h"
#include "task/test_pool.h"
#include <map>

int main() {
        logxx::SetLogLevel(logxx::warning);
        bool res(true);
        logxx::Log log("main");
        
        log(logxx::info) << "Starting tests" << logxx::endl;
        std::map<std::string, bool> tests {
                {"server", false},
                {"tast", false},
                {"pool", true}
        };
        
        if (tests["server"]){
                TestServer testServer;
                res &= testServer.RunTests();
        }
        
        if (tests["tast"]){
                TestTask testTask;
                res &= testTask.RunTests();
        }
        
        if (tests["pool"]){
                TestPool testPool;
                res &= testPool.RunTests();
        }
        
        auto &s = log(logxx::info) << "Tests ";
        if (res)
                s << "OK";
        else
                s << "FAILED";
        s << logxx::endl;
        return res ? 0 : 1;
}

