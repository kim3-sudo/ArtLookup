//File Name: UserManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages users in user database
//Last Changed: Dec 12, 2019

#include "UserManager.h"
#include "Query.h"

void addMember(string username, string email, string password){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;

	// if member username and email not already in user database, add member
	string command = query.addUser(username,password,email);
	sqlStatement->execute(command);
}

//TEST!!!!
// Can only call if user exists!
Member UserManager::getLoginMember(string email, string password){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;
	string loginResultsCommand = query.loginResults(email,password);
	sqlStatement->execute(loginResultsCommand);
	std::unique_ptr<sql::ResultSet> loginMatches;
	loginMatches.reset(sqlStatement->getResultSet());
	int memberId;
	string username;
	while (loginMatches->next()){
		// This loop should only run once
		memberId = loginMatches -> getInt(userColNames[0]);
		username = loginMatches -> getString(userColNames[1]);
	}
	// MUST get username from SQL results
	Member *member;
	member = new Member(memberId, username, password, email);
	return *member;
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
	// Establish connection and create SQL statement
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	// Create query object and obtain appropriate SQL command
	Query query; 
	string findEmailCommand = query.findUserEmail(email);
	// Execute command
	sqlStatement->execute(findEmailCommand);
	// Get resultset
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


// TEST ME!!!
bool UserManager::canLogin(string email, string password){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());

	Query query; // Create query object
	string loginResultsCommand = query.loginResults(email,password);
	//string numUsersCommand = query.numUserLoginInfo(email,password);
	sqlStatement->execute(loginResultsCommand);
	std::unique_ptr<sql::ResultSet> loginMatches;
	loginMatches.reset(sqlStatement->getResultSet());
	int count(0);
	while (loginMatches->next()){
		count++;
    }
    if (count == 0){
    	return false;
    } else {
    	return true;
    }

	// loginMatches -> next(); // MAYBE wrong
	// //int numUsers = loginMatches->getInt("Count(*)");

	// // What about more than one??
	// if (numUsers == 1){
	// 	return true;
	// } else {
	// 	return false;
	// }

	// while (emailMatches->next()){
	// 	cout << 
	// }

	// The SQL statement returns a number; how do I obtain that number?
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



