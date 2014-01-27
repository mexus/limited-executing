#ifndef TESTSERVER_H
#define	TESTSERVER_H

#include "../test_fw.h"
#include "../../main/server/server.h"

class TestServer : public TestFW {
public:
        TestServer();
        virtual ~TestServer();
        
private:
        static logxx::Log cLog;

        virtual bool Tests();

};

#endif	/* TESTSERVER_H */

