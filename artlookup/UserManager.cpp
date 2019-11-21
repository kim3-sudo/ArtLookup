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
	// string command = query.addUser();

	// sqlStatement->execute(command);





	// std::unique_ptr<sql::ResultSet> searchMatches; // Create ResultSet object

	// int intResults[2]; // hold results for artId and Likes
	// string strResults[11]; // hold results with str type
	// Artwork *artwork; // use pointer to dynamically create and destroy Artwork objects
	// vector<Artwork> artworkResultList; // Vector to hold Artwork objects from search

	// do {
	// searchMatches.reset(sqlStatement->getResultSet());
	// while (searchMatches->next()) {
	//   // Get results
	//   intResults[0] = searchMatches -> getInt(colNames[0]); // artId
	//   for (int i=1;i<12;i++){
	//     strResults[i-1] = searchMatches -> getString(colNames[i]);
	//   }
	//   intResults[1] = searchMatches -> getInt(colNames[12]); // Likes

	//   //Use pointer to dynamically create artwork
	//   artwork = new Artwork(intResults[0],strResults[0],strResults[1],strResults[2],strResults[3],strResults[4],strResults[5],strResults[6],strResults[7],strResults[8],strResults[9],strResults[10],intResults[1]);

	//   artworkResultList.push_back(*(artwork));
	//   delete artwork; // Deallocate memory in artwork once finished with object
	// }
	// } while (sqlStatement->getMoreResults());
	// return artworkResultList;
    
}

// add member to user table in sql database

// Maybe change input to member?? Probably not
bool UserManager::isValidMember(string in_username, string password);
// Returns true if there is a member with username in_username and 
// password in_password; false otherwise

UserManager::UserManager(){
	// Default Constructor
	// Maybe delete?
}