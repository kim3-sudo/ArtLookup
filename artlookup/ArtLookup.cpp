#include "ArtLookup.h"

//Default Constructor.
ArtLookup::ArtLookup(){

}

/*
Preconditions: "search" will be a string corresponding to the search
  term input by the user on the webpage. Art table must exist.
Postconditions: Returns a vector of Artworks that have data that matches
  "search".
*/
vector<Artwork> ArtLookup::lookupAll(string search){

  vector<Artwork> authorMatches = lookupSingle(search, "Author"),
  lifespanMatches = lookupSingle(search, "Born-Diec"),
  vector<Artwork> titleMatches = lookupSingle(search, "Title"),
  vector<Artwork> dateMatches = lookupSingle(search, "Date"),
  vector<Artwork> techniqueMatches = lookupSingle(search, "Technique"),
  vector<Artwork> locationMatches = lookupSingle(search, "Location"),
  vector<Artwork> formMatches = lookupSingle(search, "Form"),
  vector<Artwork> typeMatches = lookupSingle(search, "Type"),
  vector<Artwork> schoolMatches = lookupSingle(search, "School"),
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

/*
Preconditions: "search" will be a string corresponding to the search
  term input by the user on the webpage. "colName" will be a string
  corresponding to the catagory the user wants to search and will match
  one of the names of the columns in the art table. Art table must exist.
Postconditions: Returns a vector of Artworks that have data in the
  "colName" column that matches "search".
*/
vector<Artwork> ArtLookup::lookupSingle(string search, string colName){
  auto_ptr<Connection> connectionToDB = establishDBConnection();
  auto_ptr<Statement> sqlStatement(conectionToDB->createStatement());

  vector<Artwork> artworkResultList;
  sqlStatement->execute("SELECT * FROM art WHERE " + colName + " like '%" + search + "%'");

  auto_ptr<ResultSet> queryMatches;
  Artwork artwork;
  do {
    queryMatches.reset(sqlStatement->getResultSet());
    while (queryMatches->next()) {
      //I am unsure if we are allowed to split this command up into different
      //lines like I did. Probably but I never do it so I don't know for sure.
      //Creates artwork
      artwork = Artwork(queryMatches -> getstring("artId"),
      queryMatches -> getstring("Author"),
      queryMatches -> getstring("Born-Diec"), //This misspelling is on purpose
      queryMatches -> getstring("Title"), queryMatches -> getstring("Date"),
      queryMatches -> getstring("Technique"),
      queryMatches -> getstring("Location"),
      queryMatches -> getstring("URL"), queryMatches -> getstring("Form"),
      queryMatches -> getstring("Type"),
      queryMatches -> getstring("School"),
      queryMatches -> getstring("Timeframe"),
      queryMatches -> getstring("Likes")) //Likes does not exist in our table yet

	    artworkResultList.push_back(artwork);
    }
  } while (sqlStatement->getMoreResults());

  return artworkResultList
}

/*
Preconditions: Art table must exist.
Postconditions: Returns an array of 10 Artworks that have the most likes.
  (Future versions may return array of 10 Artworks that have the most
  likes per day/week).
*/
Artwork[10] ArtLookup::topLikedLookup(){
  //Micaela Assigned
}
