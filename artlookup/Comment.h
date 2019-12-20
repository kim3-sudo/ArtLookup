#include <string>
using std::string;

#ifndef COMMENT_H
#define COMMENT_H

class Comment {
	public:
		// Accesor Functions
		string getCommentId();
		string getComment();
		string getCommentOnId();
		string getCommentOnType();
		string getUserId();
		int getNumLikes();

		// Constructors
		Comment(string commentId, string comment, string commentOnId, string commentOnType, string userId, int numLikes);
		Comment();
	private:
    	string m_commentId;
		string m_comment;
		string m_commentOnId;
		string m_commentOnType;
		string m_userId;
		int m_numLikes;
};

#endif //COMMENT_H


