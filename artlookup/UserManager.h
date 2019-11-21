
#include "ArtDBCommunicator.h"
#include "Member.h"

#ifndef USER_MANAGER_H
#define USER_MANAGER_H

class UserManager: public ArtDBCommunicator{
  public:
    void addMember(Member member);
    // add member to user table in sql database

    // Maybe change input to member?? Probably not
    bool isValidMember(string in_username, string password);
    // Returns true if there is a member with username in_username and 
    // password in_password; false otherwise
  
    UserManager();
    // Default Constructor
};

#endif //USER_MANAGER_H
