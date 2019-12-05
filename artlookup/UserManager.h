
#include "ArtDBCommunicator.h"
#include "Member.h"
#include <vector>

#ifndef USER_MANAGER_H
#define USER_MANAGER_H

class UserManager: public ArtDBCommunicator{
	public:
	    void addMember(Member member);
	    // add member to user table in sql database

	    bool isUsernameTaken(string username);
	    // Returns true if username taken; false otherwise

	    bool isEmailTaken(string email);
	    // Returns true if email taken; false otherwise

	    //bool isExistingMember(Member member);
	    // Returns true if there is a member with username in_username and 
	    // password in_password; false otherwise
	  
	    UserManager();
	    // Default Constructor
	private:
    	vector<string> userColNames;
};

#endif //USER_MANAGER_H