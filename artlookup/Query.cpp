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

// EDIT other member functions to have same format
string Query::numUserLoginInfo(string email,string password){
	return "SELECT COUNT(*) FROM `users` WHERE email = '" + email + "' and password = '" + password + "';";
}

string Query::addUser(string username, string password, string email){
	return "INSERT INTO `users`(`userId`, `userName`, `password`, `email`) VALUES (NULL,'" + username
		+ "','" + password + "','" + email + "');";
}