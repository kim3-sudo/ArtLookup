#include "ArtDBCommunicator.h"
#include "Member.h"
#include <vector>

#ifndef COMMENT_MANAGER_H
#define COMMENT_MANAGER_H

class CommentManager: public ArtDBCommunicator{
	public:
	    void addComment(string artId, string comment, string memberId);
	    // add comment to user table in sql database

	    //Member getLoginMember(string email, string password);
	    // Given login info, returns member object
	  
	    CommentManager();
	    // Default Constructor
	private:
    	vector<string> commentColNames;
};

#endif //COMMENT_MANAGER_H
