//File Name: Query.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Class for obtaining appropriate queries
//Last Changed: November 13, 2019

#include "Query.h"

// Edit if database should be general
string Query::matchSingleCol(string searchItem, string colName){
	return "SELECT * FROM art WHERE " + colName + " LIKE  '%" + searchItem + "%'";
}

string Query::findUser(string username){
	return "SELECT * FROM users WHERE userName = '" + username + "'";
}

string Query::addUser(string username, string password, string email){
	return "INSERT INTO `users`(`userId`, `userName`, `password`, `email`) VALUES (NULL,'" + username + "','" + password + "','" + email + "');";
}
