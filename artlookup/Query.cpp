//File Name: Query.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Class for obtaining appropriate queries
//Last Changed: November 13, 2019

#include "Query.h"

// Edit if database should be general
string Query::matchSingleCol(string searchItem, string colName){
	return "SELECT * FROM art WHERE " + colName + " LIKE  '%" + searchItem + "%';";
}

string Query::findUserUsername(string username){
	return "SELECT * FROM users WHERE userName = '" + username + "';";
}

string Query::findUserEmail(string email){
	return "SELECT * FROM users WHERE email = '" + email + "';";
}

string Query::loginResults(string email,string password){
	return "SELECT * FROM `users` WHERE email = '" + email + "' and password = '" + password + "';";
	//return "SELECT COUNT(*) FROM `users` WHERE email = '" + email + "' and password = '" + password + "';";
}

string Query::addUser(string username, string password, string email){
	return "INSERT INTO `users`(`userId`, `userName`, `password`, `email`) VALUES (NULL,'" + username
		+ "','" + password + "','" + email + "');";
}

string Query::addComment(string artId, string commentOnType, string comment, string userId){
	return "INSERT INTO `comments`(`commentId`, `commentOnId`, `commentOnType`, `comment`, `userId`, `numLikes`) VALUES (NULL,'"+ artId +"','" + commentOnType +"','" + comment + "','" + userId + "',0);";
}

string Query::addLike(string itemId, string userId){
	return "INSERT INTO `likes`(`likeId`, `userId`, `itemId`, `itemType`) VALUES (NULL,'"+ userId +"','" + itemId +"','" + "',artwork);";
}

string Query::getComments(string commentOnId, string commentOnType){
	return "SELECT * FROM comments WHERE commentOnId = '" + commentOnId + "' and commentOnType = '" + commentOnType + "';";
}

string Query::getLikes(string itemId){
	return "SELECT * FROM likes WHERE commentOnId = '" + itemId + "';";
}

string Query::getUsername(string userId){
	return "SELECT * FROM `users` WHERE userId = '" + userId + "';";
}

string Query::updateNumLikes(string numLikes, string artId){
	return "UPDATE art SET Likes = " + numLikes + " WHERE artId = '" + artId + "';";
}
