#include <string>

using std::string;

#ifndef QUERY_H
#define QUERY_H

class Query{
  public:
    string matchSingleCol(string search, string colName);
    // Returns query command to search all columns with colName like search

    string findUser(string username);
    // Usernames must be unique; query to see if there are any entries in user table 
    // with userName = username 

    string addUser(string username, string password, string email);
    // query to add user to database

};

#endif //QUERY_H
