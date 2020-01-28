//File Name: Comment.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Implementation file for Comment class
//Last Changed: Dec 19, 2019

// Added a comment

#include "Comment.h"

string Comment::getCommentId(){
	return m_commentId;
}

string Comment::getComment(){
	return m_comment;
}

string Comment::getCommentOnId(){
	return m_commentOnId;
}

string Comment::getCommentOnType(){
	return m_commentOnType;
}

string Comment::getUserId(){
	return m_userId;
}

int Comment::getNumLikes(){
	return m_numLikes;
}

Comment::Comment(string commentId, string comment, string commentOnId, string commentOnType, string userId, int numLikes){
	m_commentId = commentId;
	m_comment = comment;
	m_commentOnId = commentOnId;
	m_commentOnType = commentOnType;
	m_userId = userId;
	m_numLikes = numLikes;
}

Comment::Comment(){
	m_commentId = "";
	m_comment = "";
	m_commentOnId = "";
	m_commentOnType = "";
	m_userId = "";
	m_numLikes = 0;
}









