#include <string>

using std::string;

#ifndef QUERY_H
#define QUERY_H

class Query{
  public:
    string matchSingleCol(string search, string colName);
    // Returns query command to search all columns with colName like search

    string findUsers(string username,string email);
    // Usernames and emails must be unique; query returns all members with 
    // userName = username or email = email

    string addUser(string username, string password, string email);
    // query to add user to database
};

#endif //QUERY_H
