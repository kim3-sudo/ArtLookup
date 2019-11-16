//File Name: ArtLookup.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Inherits from ArtDBCommunicator. Communicates specifically
//with art table in our database
//Last Changed: November 16, 2019

#include "ArtLookup.h"
#include "Query.h"

vector<Artwork> ArtLookup::lookupGeneral(string search){
  Query query; // Create query object for commands
  string authorCommand = query.matchSingleCol(search,colNames[1]), titleCommand = query.matchSingleCol(search,colNames[3]), techniqueCommand = query.matchSingleCol(search,colNames[4]), locationCommand = query.matchSingleCol(search,colNames[5]), formCommand = query.matchSingleCol(search,colNames[7]), typeCommand = query.matchSingleCol(search,colNames[9]), schoolCommand = query.matchSingleCol(search,colNames[9]), timeframeCommand = query.matchSingleCol(search,colNames[10]), dateCommand = = query.matchSingleCol(search,colNames[11]);

  vector<Artwork> authorMatches = lookupSingleCommand(authorCommand), titleMatches = lookupSingleCommand(titleCommand), techniqueMatches = lookupSingleCommand(techniqueCommand), locationMatches = lookupSingleCommand(locationCommand), formMatches = lookupSingleCommand(formCommand), typeMatches = lookupSingleCommand(typeCommand), schoolMatches = lookupSingleCommand(schoolCommand), timeframeMatches = lookupSingleCommand(timeframeCommand), dateMatches = lookupSingleCommand(dateCommand);

  //Concatenate vectors https://stackoverflow.com/questions/201718/concatenating-two-stdvectors vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
  vector<Artwork> allMatches = authorMatches;
  //allMatches.insert( allMatches.end(), lifespanMatches.begin(), lifespanMatches.end() );
  allMatches.insert( allMatches.end(), titleMatches.begin(), titleMatches.end() );
  allMatches.insert( allMatches.end(), techniqueMatches.begin(), techniqueMatches.end() );
  allMatches.insert( allMatches.end(), locationMatches.begin(), locationMatches.end() );
  allMatches.insert( allMatches.end(), formMatches.begin(), formMatches.end() );
  allMatches.insert( allMatches.end(), typeMatches.begin(), typeMatches.end() );
  allMatches.insert( allMatches.end(), schoolMatches.begin(), schoolMatches.end() );
  allMatches.insert( allMatches.end(), timeframeMatches.begin(), timeframeMatches.end() );
  allMatches.insert( allMatches.end(), dateMatches.begin(), dateMatches.end() );

  return allMatches;
}

// General search
vector<Artwork> ArtLookup::lookupSingleCommand(string command){
  std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
  // Not sure why sqlStatement(connectionToDB...) works but not sqlStatement = connectionToDB...
  std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());

  sqlStatement->execute(command);
  
  std::unique_ptr<sql::ResultSet> searchMatches; // Create ResultSet object
  int intResults[2]; // hold results for artId and Likes
  string strResults[11]; // hold results with str type
  Artwork *artwork; // use pointer to dynamically create and destroy Artwork objects
  vector<Artwork> artworkResultList; // Vector to hold Artwork objects from search

  do {
    searchMatches.reset(sqlStatement->getResultSet());    
    while (searchMatches->next()) {
      // Get results
      intResults[0] = searchMatches -> getInt(colNames[0]); // artId
      for (int i=1;i<11;i++){
        strResults[i-1] = searchMatches -> getString(colNames[i]);
      }
      intResults[1] = searchMatches -> getInt(colNames[12]); // Likes

      //Use pointer to dynamically create artwork
      artwork = new Artwork(intResults[0],strResults[0],strResults[1],strResults[2],strResults[3],strResults[4],strResults[5],strResults[6],strResults[7],strResults[8],strResults[9],strResults[10],intResults[1]);
      
      artworkResultList.push_back(*(artwork));
      delete artwork; // Deallocate memory in artwork once finished with object
    }
  } while (sqlStatement->getMoreResults());
  return artworkResultList;
}

ArtLookup::ArtLookup(){
  colNames.push_back("artId");
  colNames.push_back("Author");
  colNames.push_back("Born-Diec");
  colNames.push_back("Title");
  colNames.push_back("Technique");
  colNames.push_back("Location");
  colNames.push_back("URL");
  colNames.push_back("Form");
  colNames.push_back("Type");
  colNames.push_back("School");
  colNames.push_back("Timeframe");
  colNames.push_back("Date");
  colNames.push_back("Likes");
}

/****** OLD CODE ****************************************************/

/*
vector<Artwork> ArtLookup::lookupGeneral(string search){

  //vector<Artwork> authorMatches; // Default returned
  //vector<Artwork> authorMatches = lookupSingle(search, "Author");


  vector<Artwork> authorMatches = lookupSingle(search, "Author"),
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
  //allMatches.insert( allMatches.end(), lifespanMatches.begin(), lifespanMatches.end() );
  allMatches.insert( allMatches.end(), titleMatches.begin(), titleMatches.end() );
  allMatches.insert( allMatches.end(), dateMatches.begin(), dateMatches.end() );
  allMatches.insert( allMatches.end(), techniqueMatches.begin(), techniqueMatches.end() );
  allMatches.insert( allMatches.end(), locationMatches.begin(), locationMatches.end() );
  allMatches.insert( allMatches.end(), formMatches.begin(), formMatches.end() );
  allMatches.insert( allMatches.end(), typeMatches.begin(), typeMatches.end() );
  allMatches.insert( allMatches.end(), schoolMatches.begin(), schoolMatches.end() );
  allMatches.insert( allMatches.end(), timeframeMatches.begin(), timeframeMatches.end() );
  
  //return authorMatches;
  return allMatches;
}
*/

/*
vector<Artwork> ArtLookup::lookupSingle(string search, string colName){
  //auto_ptr<Connection> connectionToDB = establishConnection();
  //auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());
  std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
  std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  string hardCommand, addStrCommand;

  //hardCommand = "SELECT * FROM art WHERE Title LIKE '%Joking Couple%';";
  addStrCommand = "SELECT * FROM art WHERE " + colName + " LIKE '%" + search + "%';";
  
  //sqlStatement->execute("SELECT * FROM art WHERE " + colName + " LIKE '%" + search + "%';");
  sqlStatement->execute(addStrCommand);
  //cout << hardCommand << endl;
  //cout << addStrCommand << endl;
  //sqlStatement->execute(addStrCommand);

  
  //auto_ptr<ResultSet> searchMatches;
  std::unique_ptr<sql::ResultSet> searchMatches;

  //string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  string strResults[11]; // hold results with str type
  int intResults[2]; // hold results for artId and Likes
  
  do {
    searchMatches.reset(sqlStatement->getResultSet());
    
    // add artId val to intResults

    if(!searchMatches->next()){
      cout << "No results : ( \n";
    }else{
    // PROBLEM????
    intResults[0] = searchMatches -> getInt(colNames[0]);
    // add string vals to strResults
    }    
    
    for (int i=1;i<11;i++){
      strResults[i-1] = searchMatches -> getString(colNames[i]);
    }
    
    // add Likes val to intResults
    intResults[1] = searchMatches -> getInt(colNames[12]);

    while (searchMatches->next()) {
      //Creates artwork

      Artwork artwork = Artwork(intResults[0],strResults[0],strResults[1],strResults[2],strResults[3],strResults[4],strResults[5],strResults[6],strResults[7],strResults[8],strResults[9],strResults[10],intResults[1]);

	    artworkResultList.push_back(artwork);
	    }
    //} while (false);
  } while (sqlStatement->getMoreResults());
  return artworkResultList;
}
*/

/*
vector<Artwork> ArtLookup::topLikedLookup(){
  //auto_ptr<Connection> connectionToDB = establishConnection();
  //auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());
  std::unique_ptr<sql::Connection> connectionToDB = establishDBConnection();
  std::unique_ptr<sql::Statement> sqlStatement(connectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  sqlStatement->execute("SELECT * FROM art ORDER BY Likes,Title ASC LIMIT 10;");

  //auto_ptr<ResultSet> searchMatches;
  std::unique_ptr<sql::ResultSet> searchMatches;
  //string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  string strResults[11]; // hold results with str type
  int intResults[2]; // hold results for artId and Likes

  do {
    searchMatches.reset(sqlStatement->getResultSet());

    // add artId val to intResults
    intResults[0] = searchMatches -> getInt(colNames[0]);
    // add string vals to strResults
    for (int i=1;i<12;i++){
      strResults[i-1] = searchMatches -> getString(colNames[i]);
    }
    // add Likes val to intResults
    intResults[1] = searchMatches -> getInt(colNames[12]);

    while (searchMatches->next()) {
      //The column "Likes" has yet to be created
      //I am unsure if we are allowed to split this command up into differnet
      //lines like I did. Probably but I never do it so I don't know for sure.
      //Creates artwork
      Artwork artwork = Artwork(intResults[0],strResults[0],strResults[1],strResults[2],strResults[3],strResults[4],strResults[5],strResults[6],strResults[7],strResults[8],strResults[9],strResults[10],intResults[1]);

      artworkResultList.push_back(artwork);
    }
  } while (sqlStatement->getMoreResults());
  return artworkResultList;
}
*/






