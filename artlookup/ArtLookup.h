// #include "mysql_connection.h"
// #include "mysql_driver.h"
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>

// using sql::driver;
// using sql::mysql;
// using sql::Statement;
// using sql::ResultSet;
// using std::auto_ptr;

#include <string>
#include <vector>
#include "Artwork.h"

// #define HOST "localhost"
// #define USER "schultz4"
// #define DB "Team5"
// #define PASS "S218269"

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup : ArtDBCommunicator{
  public:
  	vector<Artwork> lookupAll(string search);
  	vector<Artwork> lookupSingle(string search, string colName);
  	// Maybe return array of size 10????
  	Artwork[10] topLikedLookup();
  private:
};

#endif //ART_LOOKUP_H
