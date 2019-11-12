#include <string>

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using sql::driver;
using sql::mysql;
using sql::Statement;
using sql::ResultSet;
using std::auto_ptr;

#ifndef ARTDBCOMMUNICATOR_H
#define ARTDBCOMMUNICATOR_H

class ArtDBCommunicator{
  public:

  private:
    const string password;
    const string DBname;
    const string address;
    const string DBUsername;
};

#endif ARTDBCOMMUNICATOR_H
