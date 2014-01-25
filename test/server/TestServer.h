/* 
 * File:   TestServer.h
 * Author: mexus
 *
 * Created on January 24, 2014, 12:13 PM
 */

#ifndef TESTSERVER_H
#define	TESTSERVER_H

#include "../../main/server/server.h"

class TestServer {
public:
        TestServer();
        virtual ~TestServer();
        
        bool RunTests();
private:
        
        static logxx::Log cLog;

};

#endif	/* TESTSERVER_H */

