//File Name: ArtLookup.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Inherits from ArtDBCommunicator. Communicates specifically
//with art table in our database
//Last Changed: November 13, 2019

#include "ArtLookup.h"

vector<Artwork> ArtLookup::lookupAll(string search){

  vector<Artwork> authorMatches = lookupSingle(search, "Author");
  vector<Artwork> lifespanMatches = lookupSingle(search, "Born-Diec"); //Do we want the user to be able to lookup by lifespan of artist
  vector<Artwork> titleMatches = lookupSingle(search, "Title");
  vector<Artwork> dateMatches = lookupSingle(search, "Date");
  vector<Artwork> techniqueMatches = lookupSingle(search, "Technique");
  vector<Artwork> locationMatches = lookupSingle(search, "Location");
  vector<Artwork> formMatches = lookupSingle(search, "Form");
  vector<Artwork> typeMatches = lookupSingle(search, "Type");
  vector<Artwork> schoolMatches = lookupSingle(search, "School");
  vector<Artwork> timeframeMatches = lookupSingle(search, "Timeframe");

  //concatenate vectors https://stackoverflow.com/questions/201718/concatenating-two-stdvectors
  //vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
  vector<Artwork> allMatches = authorMatches;
  allMatches.insert( allMatches.end(), lifespanMatches.begin(), lifespanMatches.end() );
  allMatches.insert( allMatches.end(), titleMatches.begin(), titleMatches.end() );
  allMatches.insert( allMatches.end(), dateMatches.begin(), dateMatches.end() );
  allMatches.insert( allMatches.end(), techniqueMatches.begin(), techniqueMatches.end() );
  allMatches.insert( allMatches.end(), locationMatches.begin(), locationMatches.end() );
  allMatches.insert( allMatches.end(), formMatches.begin(), formMatches.end() );
  allMatches.insert( allMatches.end(), typeMatches.begin(), typeMatches.end() );
  allMatches.insert( allMatches.end(), schoolMatches.begin(), schoolMatches.end() );
  allMatches.insert( allMatches.end(), timeframeMatches.begin(), timeframeMatches.end() );

  return allMatches;

}
vector<Artwork> Artlookup::lookupSingle(string search, string colName){
  auto_ptr<Connection> connectionToDB = establishConnection();
  auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  sqlStatement->execute("SELECT * FROM art WHERE " + colName + " like '%" + search + "%'");

  auto_ptr<ResultSet> searchMatches;
  do {
    searchMatches.reset(stmt->getResultSet());
    while (searchMatches->next()) {
      //The column "Likes" has yet to be created
      //I am unsure if we are allowed to split this command up into differnet
      //lines like I did. Probably but I never do it so I don't know for sure.
      //Creates artwork
      Artwork artwork = Artwork(searchMatches -> getstring("artId"),
      searchMatches -> getstring("Author"),
      searchMatches -> getstring("Born-Diec"), //This misspelling is on purpose
      searchMatches -> getstring("Title"), searchMatches -> getstring("Date"),
      searchMatches -> getstring("Technique"),
      searchMatches -> getstring("Location"),
      searchMatches -> getstring("URL"), searchMatches -> getstring("Form"), searchMatches -> getstring("Type"), searchMatches -> getstring("School"), searchMatches -> getstring("Timeframe"),
      searchMatches -> getstring("Likes"))

	    artworkResultList.push_back(artwork);
    }
  } while (sqlStatement->getMoreResults());

  return artworkResultList
}
// Maybe return array of size 10????
vector<Artwork> Artlookup::topLikedLookup(){

}
