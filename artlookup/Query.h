#include <string>

using std::string;

#ifndef QUERY_H
#define QUERY_H

class Query{
  public:
    string matchSingleCol(string search, string colName);
    // Returns query command to search all columns with colName like search

    string findUserUsername(string username);
    // Usernames must be unique; query returns all members with 
    // userName = username

	string findUserEmail(string email);
	// Emails must be unique; query returns all members with 
    // email = email

    string loginResults(string email,string password);
    // Emails must be unique; query returns all members with 
    // email = email

    string addUser(string username, string password, string email);
    // query to add user to database

    string addComment(string artId, string commentOnType, string comment, string userId);
    // query to add comment to database

    string getComments(string commentOnId, string commentOnType);
    // query to select comments on a specific artwork or comment

    string getUsername(string userId);
    // query to select user with userId
};

#endif //QUERY_H
