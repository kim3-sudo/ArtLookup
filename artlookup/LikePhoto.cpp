#include "ArtLookup.h"
#include "JSCommunicator.h"
#include "Query.h"
#include "Artwork.h"
#include <iostream>
#include <string>

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

int main(){
  Cgicc cgi; // Ajax object

  JSCommunicator jSCommunicator;
  // Ajax objects receive info from web page
  string artId = jSCommunicator.getElement( "artId", cgi );

  Query query;
  // Creates query to search for the artId value in the artId column
  string artIdQuery = query.matchSingleCol(artId, "artId");

  ArtLookup artlookup;
  // Looks for artwork that match the artId given by the javascript
  vector<Artwork> likedArtworks = artlookup.lookupSingleCommand(artIdQuery);
  Artwork likedArtwork = likedArtworks.at(0);

  // Likes artwork and gets the new number of likes.
  likedArtwork.incrementLikes();
  int numLikes = likedArtwork.getNumLikes();
  string updatedLikes = to_string(numLikes);

  // Updates number of likes in art table in database
  //string updateLikesQuery = query.updateNumLikes(updatedLikes, artId);

  //artlookup.updateTable(updateLikesQuery);

  // Sends the new number of likes to javascript.
  jSCommunicator.sendStringToJS(updatedLikes + "*" + artId);
  return 0;
}
