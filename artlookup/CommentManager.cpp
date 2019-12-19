//File Name: CommentManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages comments in user database
//Last Changed: Dec 12, 2019

#include "CommentManager.h"
#include "Query.h"

using std::to_string;

// This is nearly identical to addMember in UserManager
void CommentManager::addComment(string artId, string commentOnType, string comment, string memberId){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;

	// if member username and email not already in user database, add member
	string addCommentQuery = query.addComment(artId, commentOnType, comment, memberId);
	sqlStatement->execute(addCommentQuery);
}

vector<Comment> CommentManager::getComments(int commentOnId, string commentOnType){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;
	string getCommentsQuery = query.getComments(to_string(commentOnId), commentOnType);
	sqlStatement->execute(getCommentsQuery);

	std::unique_ptr<sql::ResultSet> searchMatches;
	Comment *comment;
	vector<Comment> commentResultList;
	int commentId, userId, numLikes;
	string commentText;

	do {
	searchMatches.reset(sqlStatement->getResultSet());
    while (searchMatches->next()) {
      // Get results
      commentId = searchMatches -> getInt(commentColNames[0]); 
      //commentOnId = searchMatches -> getInt(commentColNames[1]);
      //commentOnType = searchMatches -> getString(commentColNames[2]);
      commentText = searchMatches -> getString(commentColNames[3]);
      userId = searchMatches -> getInt(commentColNames[4]);
      numLikes = searchMatches -> getInt(commentColNames[5]);

      //Use pointer to dynamically create comment
      comment = new Comment(commentId,commentText,commentOnId,commentOnType,userId,numLikes);

      commentResultList.push_back(*(comment));
      delete comment; // Deallocate memory in comment once finished with object
    }
  } while (sqlStatement->getMoreResults());
  return commentResultList;
}

CommentManager::CommentManager(){
	commentColNames.push_back("commentId");
	commentColNames.push_back("commentOnId");
	commentColNames.push_back("commentOnType");
	commentColNames.push_back("comment");
	commentColNames.push_back("userId");
	commentColNames.push_back("numLikes");
}

