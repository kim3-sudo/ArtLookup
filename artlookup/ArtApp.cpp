#include "ArtLookup.h"
#include "Query.h"
#include <iostream>
// Maybe unnecessary
#include <string>


// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc.HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

class JSCommunicator(){
  string print(Artwork artwork){
    //Prints artwork data to JavaScript delimited by *^. It is possible to do
    //multi-character delimination in JavaScript.
    string result, sep("*^");
    result += artwork.getArtId() + sep + artwork.getArtistInfo().author + sep + artwork.getArtistInfo().birthDeath + sep + artwork.getTitle() + sep + artwork.getArtStyle().technique + sep + artwork.getArtSetting().location + sep + artwork.getUrl() + sep + artwork.getArtStyle().form + sep + artwork.getArtStyle().type + sep + artwork.getArtStyle().school + sep + artwork.getArtSetting().timeframe + sep + artwork.getArtSetting().date + sep + artwork.getNumLikes()
    return result;
  }
}

int main(){
  Cgicc cgi; // Ajax object
  char *cstr;
  // Ajax object to receive info from web page
  form_iterator itSearch = cgi.getElement("searchVal");
  string searchVal = **itSearch;

  Artlookup artlookup;
  Query query;

  //Vector of artworks. Created using matchSingleCol query for our lookupSingleCommand function.
  vector<Artwork> searchByTitle(artlookup.lookupSingleCommand(query.matchSingleCol(searchVal,"Title")));

  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"},result("Content-Type: text/plain\n\n");

  Artwork artwork;
  JSCommunicator jSCommunicator;

  //Sends artwork data to JavaScript
  for (uint i=0;i<searchByTitle.size()){
    artwork = searchByTitle.at(i);
    result += jSCommunicator.print(artwork);
  }
  cout << result;

  return 0;
}
