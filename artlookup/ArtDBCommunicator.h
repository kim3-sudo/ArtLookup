#include <string>

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

// ERROR: has not been declared
sql::Driver *driver;
sql::Connection *connection;
sql::Statement *stm;
sql::ResultSet *res;


// ERROR: namespace 'sql::mysql' not allowed in using-declaration
//using sql::mysql;
//using sql::Connection;
//using sql::Statement;
//using sql::ResultSet;
//using std::auto_ptr;

#ifndef ARTDBCOMMUNICATOR_H
#define ARTDBCOMMUNICATOR_H

#define HOST "localhost"
#define USER "schultz4"
#define DB "Team5"
#define PASS "S218269"

class ArtDBCommunicator{
  public:
    ArtDBCommunicator();

    // ERROR: template<class> class std::auto_ptr is deprecated 
    auto_ptr<Connection> establishConnection();
  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
};

#endif //ARTDBCOMMUNICATOR_H
