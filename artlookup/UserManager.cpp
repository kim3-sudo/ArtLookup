//File Name: UserManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages users in user database
//Last Changed: Dec 4, 2019

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

bool UserManager::isUsernameTaken(string username){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query; // Create query object
	string findUsernameCommand = query.findUserUsername(username);
	sqlStatement->execute(findUsernameCommand);
	std::unique_ptr<sql::ResultSet> usernameMatches; // Create ResultSet objects
	usernameMatches.reset(sqlStatement->getResultSet());
	int count(0);
	while (usernameMatches->next()) {
		count++;
    }
    if (count == 0){
    	return false;
    } else {
    	return true;
    }
}
// Returns true if username taken; false otherwise

bool UserManager::isEmailTaken(string email){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query; // Create query object
	string findEmailCommand = query.findUserEmail(email);
	sqlStatement->execute(findEmailCommand);
	std::unique_ptr<sql::ResultSet> emailMatches; // Create ResultSet objects
	emailMatches.reset(sqlStatement->getResultSet());
	int count(0);
	while (emailMatches->next()) {
		count++;
    }
    if (count == 0){
    	return false;
    } else {
    	return true;
    }
}
// Returns true if email taken; false otherwise

bool UserManager::canLogin(string email, string password){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query; // Create query object
	string numUsersCommand = query.numUserLoginInfo(email,password);
	sqlStatement->execute(numUsersCommand);



	// The SQL statement returns a number; how do I obtain that number?


	// std::unique_ptr<sql::ResultSet> loginMatches; // Create ResultSet objects
	// loginMatches.reset(sqlStatement->getResultSet());
	// //int count(0);
	// while (emailMatches->next()) {
	// 	count++;
 //    }
 //    if (count == 0){
 //    	return false;
 //    } else {
 //    	return true;
 //    }
}










// Maybe change input to member?? Probably not
// How do we want this one to work????
// bool UserManager::isExistingMember(Member member){
// 	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
// 	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
// 	Query query;

// 	string findUsernameCommand( query.findUserUsername( member.getUsername() ) ), findEmailCommand( query.findUserEmail( member.getEmail() ) );
// 	sqlStatement->execute(repeatUsersCommand);

// 	std::unique_ptr<sql::ResultSet> usernameMatches, emailMatches; // Create ResultSet objects
	
// 	searchMatches.reset(sqlStatement->getResultSet());

// 	int count(0);
// 	while (searchMatches->next()) {
// 		count++;
//     }
//     //cout << count << endl;
//     if (count == 0){
//     	return false;
//     } else {
//     	return true;
//     }
// }
// Returns true if there is a member with username in_username and 
// password in_password; false otherwise


UserManager::UserManager(){
	userColNames.push_back("userId");
	userColNames.push_back("userName");
	userColNames.push_back("password");
	userColNames.push_back("email");
}



