//File Name: Comment.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Implementation file for Comment class
//Last Changed: Dec 19, 2019

#include "Comment.h"

int Comment::getCommentId(){
	return m_commentId;
}

string Comment::getComment(){
	return m_comment;
}

int Comment::getCommentOnId(){
	return m_commentOnId;
}

string Comment::getCommentOnType(){
	return m_commentOnType;
}

int Comment::getUserId(){
	return m_userId;
}

int Comment::getNumLikes(){
	return m_numLikes;
}

Comment::Comment(int commentId, string comment, int commentOnId, string commentOnType, int userId, int numLikes){
	m_commentId = commentId;
	m_comment = comment;
	m_commentOnId = commentOnId;
	m_commentOnType = commentOnType;
	m_userId = userId;
	m_numLikes = numLikes;
}

Comment::Comment(){
	m_commentId = 0;
	m_comment = "";
	m_commentOnId = 0;
	m_commentOnType = "";
	m_userId = 0;
	m_numLikes = 0;
}









