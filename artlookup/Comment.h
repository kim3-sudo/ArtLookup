#include <string>

#ifndef COMMENT_H
#define COMMENT_H

class Comment {
	public:
		// Accesor Functions
		int getCommentId();
		string getComment();
		int getCommentOnId();
		string getCommentOnType();
		int getUserId();
		int getNumLikes();

		// Constructors
		Comment(int commentId, string comment, int commentOnId, string commentOnType, int userId, int numLikes);
		Comment();
	private:
    	int m_commentId;
		string m_comment;
		int m_commentOnId;
		string m_commentOnType;
		int m_userId;
		int m_numLikes;
};

#endif //COMMENT_H


