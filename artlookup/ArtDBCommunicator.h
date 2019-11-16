#include <string>

using std::string;

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#ifndef ARTDBCOMMUNICATOR_H
#define ARTDBCOMMUNICATOR_H

#define HOST "localhost"
#define USER "schultz4"
#define DB "Team5"
#define PASS "S218269"

class ArtDBCommunicator{
  public:
    ArtDBCommunicator();
    // Default Constructor

    std::unique_ptr<sql::Connection> establishDBConnection();
    // Returns sql Connection object to allow for communication with art database
    
  private:
    const string password = PASS;
    const string DBName = DB;
    const string address = HOST;
    const string DBUsername = USER;
};

#endif //ARTDBCOMMUNICATOR_H
