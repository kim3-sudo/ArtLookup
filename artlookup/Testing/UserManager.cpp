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

// Maybe change input to member?? Probably not
// How do we want this one to work????
bool UserManager::isExistingMember(Member member){
	std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;
	string repeatUsersCommand = query.findUsers(member.getUsername(),member.getEmail());
	sqlStatement->execute(repeatUsersCommand);
	int count(0);
	std::unique_ptr<sql::ResultSet> searchMatches; // Create ResultSet object
	
	searchMatches.reset(sqlStatement->getResultSet());

	while (searchMatches->next()) {
		count++;
		//searchMatches -> getString(userColNames[0]);
    }
    cout << count << endl;
    if (count == 0){
    	return false;
    } else {
    	return true;
    }

	//searchMatches -> getString(colNames[i])

	// do{
	// 	
	// 	count ++;
	// } while (sqlStatement->getMoreResults());
	// cout << count << endl;

	

  // do {
  //   searchMatches.reset(sqlStatement->getResultSet());
  //   while (searchMatches->next()) {
  //     // Get results
  //     intResults[0] = searchMatches -> getInt(colNames[0]); // artId
  //     for (int i=1;i<12;i++){
  //       strResults[i-1] = searchMatches -> getString(colNames[i]);
  //     }
  //     intResults[1] = searchMatches -> getInt(colNames[12]); // Likes

  //     //Use pointer to dynamically create artwork
  //     artwork = new Artwork(intResults[0],strResults[0],strResults[1],strResults[2],strResults[3],strResults[4],strResults[5],strResults[6],strResults[7],strResults[8],strResults[9],strResults[10],intResults[1]);

  //     artworkResultList.push_back(*(artwork));
  //     delete artwork; // Deallocate memory in artwork once finished with object
  //   }
  // } while (sqlStatement->getMoreResults());
}
// Returns true if there is a member with username in_username and 
// password in_password; false otherwise

UserManager::UserManager(){
	userColNames.push_back("userId");
	userColNames.push_back("userName");
	userColNames.push_back("password");
	userColNames.push_back("email");
}



