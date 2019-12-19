#include "ArtDBCommunicator.h"
#include "Comment.h"
#include <vector>

using std::vector;
//using std::to_string;

#ifndef COMMENT_MANAGER_H
#define COMMENT_MANAGER_H

class CommentManager: public ArtDBCommunicator{
	public:
	    void addComment(string artId, string commentOnType, string comment, string memberId);
	    // add comment to user table in sql database

	    vector<Comment> getComments(int commentOnId, string commentOnType);
	    // Returns comments associated with either a specific artwork or comment
	  
	    CommentManager();
	    // Default Constructor
	private:
    	vector<string> commentColNames;
};

#endif //COMMENT_MANAGER_H
