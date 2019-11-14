//File Name: ArtLookup.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Inherits from ArtDBCommunicator. Communicates specifically
//with art table in our database
//Last Changed: November 13, 2019

#include "ArtLookup.h"

vector<Artwork> ArtLookup::lookupAll(string search){

  vector<Artwork> authorMatches = lookupSingle(search, "Author"),
                  lifespanMatches = lookupSingle(search, "Born-Diec"),
                   //Do we want the user to be able to lookup by lifespan of artist
                  titleMatches = lookupSingle(search, "Title"),
                  dateMatches = lookupSingle(search, "Date"),
                  techniqueMatches = lookupSingle(search, "Technique"),
                  locationMatches = lookupSingle(search, "Location"),
                  formMatches = lookupSingle(search, "Form"),
                  typeMatches = lookupSingle(search, "Type"),
                  schoolMatches = lookupSingle(search, "School"),
                  timeframeMatches = lookupSingle(search, "Timeframe");

  //concatenate vectors https://stackoverflow.com/questions/201718/concatenating-two-stdvectors vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
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

// EDIT break this up differently because with topTenLiked, the only difference is the command going into the execute function
// Also, search need not be an input for topTenLiked

vector<Artwork> Artlookup::lookupSingle(string search, string colName){
  auto_ptr<Connection> connectionToDB = establishConnection();
  auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  sqlStatement->execute("SELECT * FROM art WHERE " + colName + " like '%" + search + "%';");

  auto_ptr<ResultSet> searchMatches;
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  string strResults[11]; // hold results with str type
  int intResults[2]; // hold results for artId and Likes

  do {
    searchMatches.reset(stmt->getResultSet());

    // add artId val to intResults
    intResults[0] = searchMatches -> getstring(colNames[0]);
    // add string vals to strResults
    for (int i=1;i<12;i++){
      strResults[i-1] = searchMatches -> getstring(colNames[i]);
    }
    // add Likes val to intResults
    intResults[1] = searchMatches -> getstring(colNames[12]);

    while (searchMatches->next()) {
      //Creates artwork
      Artwork artwork = Artwork(intResults[0],
                                strResults[0],
                                strResults[1],
                                strResults[2],
                                strResults[3],
                                strResults[4],
                                strResults[5],
                                strResults[6],
                                strResults[7],
                                strResults[8],
                                strResults[9],
                                strResults[10],
                                strResults[11],
                                intResults[1]);

	    artworkResultList.push_back(artwork);
    }
  } while (sqlStatement->getMoreResults());

  return artworkResultList
}

// Maybe return array of size 10????
vector<Artwork> Artlookup::topLikedLookup(){
  auto_ptr<Connection> connectionToDB = establishConnection();
  auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  sqlStatement->execute("SELECT * FROM art ORDER BY Likes,Title ASC LIMIT 10;");

  auto_ptr<ResultSet> searchMatches;
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  string strResults[11]; // hold results with str type
  int intResults[2]; // hold results for artId and Likes

  do {
    searchMatches.reset(stmt->getResultSet());

    // add artId val to intResults
    intResults[0] = searchMatches -> getstring(colNames[0]);
    // add string vals to strResults
    for (int i=1;i<12;i++){
      strResults[i-1] = searchMatches -> getstring(colNames[i]);
    }
    // add Likes val to intResults
    intResults[1] = searchMatches -> getstring(colNames[12]);

    while (searchMatches->next()) {
      //The column "Likes" has yet to be created
      //I am unsure if we are allowed to split this command up into differnet
      //lines like I did. Probably but I never do it so I don't know for sure.
      //Creates artwork
      Artwork artwork = Artwork(intResults[0],
                                strResults[0], 
                                strResults[1],
                                strResults[2],
                                strResults[3],
                                strResults[4],
                                strResults[5],
                                strResults[6],
                                strResults[7],
                                strResults[8],
                                strResults[9],
                                strResults[10],
                                strResults[11],
                                intResults[1]);

      artworkResultList.push_back(artwork);
    }
  } while (sqlStatement->getMoreResults());
  return artworkResultList
}

