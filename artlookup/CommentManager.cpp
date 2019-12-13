//File Name: CommentManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages comments in user database
//Last Changed: Dec 12, 2019

#include "CommentManager.h"
#include "Query.h"

// This is nearly identical to addMember in UserManager
void CommentManager::addComment(string artId, string comment, string memberId){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;

	// if member username and email not already in user database, add member
	string addCommentQuery = query.addComment(artId, "artwork", comment, memberId);
	sqlStatement->execute(command);
}

CommentManager::CommentManager(){
	commentColNames.push_back("commentId");
	commentColNames.push_back("commentOnId");
	commentColNames.push_back("commentOnType");
	commentColNames.push_back("comment");
	commentColNames.push_back("userId");
	commentColNames.push_back("numLikes");
}

