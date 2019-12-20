//File Name: LikeManager.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Manages likes in like table
//Last Changed: Dec 20, 2019

#include "LikeManager.h"
#include "Query.h"

using std::to_string;


LikeManager::LikeManager(){

}

// This is nearly identical to addMember in UserManager
void LikeManager::addLike(string likeId, string itemId, string userId)){
  // Establish connection to database
  std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
  // Creates and executes SQL statement
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;
	string addLikeQuery = query.addLike(likeId, itemId, userId);
	sqlStatement->execute(addLikeQuery);
}

vector<Like> LikeManager::getLikes(string itemId){
  // Establish connection to database
  std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
  // Creates and executes SQL statement
	std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());
	Query query;
	string getCommentsQuery = query.getLikes(itemId);
	sqlStatement->execute(getCommentsQuery);

	std::unique_ptr<sql::ResultSet> searchMatches;
	Like *like;
	vector<Like> likeResultList;
	int likeId, userId, itemId;
	//string itemType;

	do {
	searchMatches.reset(sqlStatement->getResultSet());
    while (searchMatches->next()) {
      // Get results
      likeId = searchMatches -> getInt(likeColNames[0]);
      userId = searchMatches -> getInt(likeColNames[1]);
      itemId = searchMatches -> getInt(likeColNames[2]);
      //itemType = searchMatches -> getString(likeColNames[3]);

      //Use pointer to dynamically create comment
      like = new Like(to_string(likeId), to_string(userId), to_string(itemId))

      likeResultList.push_back(*(like));
      delete like; // Deallocate memory in comment once finished with object
    }
  } while (sqlStatement->getMoreResults());
  return likeResultList;
}
