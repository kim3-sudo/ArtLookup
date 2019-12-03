//File Name: UserManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages users in user database
//Last Changed: November 21, 2019

#include "UserManager.h"
#include "Query.h"

void UserManager::addMember(Member member){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;

	// if member username and email not already in user database, add member
	string command = query.addUser(member.getUsername(),member.getPassword(),member.getEmail());
	sqlStatement->execute(command);
}

// add member to user table in sql database

// Maybe change input to member?? Probably not
bool UserManager::isValidMember(Member member){
	// FINISH ME!!!!!!


}
// Returns true if there is a member with username in_username and 
// password in_password; false otherwise

UserManager::UserManager(){
	// Default Constructor
	// Maybe delete?
}