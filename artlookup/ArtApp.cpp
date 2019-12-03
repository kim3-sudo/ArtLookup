#include "ArtLookup.h"
#include "Query.h"
#include <iostream>

//#include <string> no compiler errors, so probably good to remove...check?


// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

class JSCommunicator{
  public:
    string print(Artwork artwork);
    string getElement(string element, Cgicc &cgi);
};

int main(){
  Cgicc cgi; // Ajax object

  JSCommunicator jSCommunicator;

  //Receive info from web page
  string searchVal = jSCommunicator.getElement("searchVal", cgi);
  string searchCategory = jSCommunicator.getElement("searchCategory", cgi);

  ArtLookup artLookup;
  Query query;
  vector<Artwork> searchResults;

  //If the user didn't choose to search by category use general lookup to get
  //search results
  if( searchCategory == "" ){
    searchResults = artLookup.lookupGeneral( searchVal );
  }
  //Else lookup using the category they specified to get search results
  else {
    searchResults = artLookup.lookupSingleCommand( query.matchSingleCol( searchVal, searchCategory ) );
    //vector<Artwork> searchResults = artLookup.lookupSingleCommand( query.matchSingleCol( searchVal, searchCategory ) );
  }

  //Sends artwork data to JavaScript
  Artwork artwork;
  string result = "";
  for (uint i = 0; i < searchResults.size(); i++){
    artwork = searchByTitle.at(i);
    result += jSCommunicator.print(artwork);
  }
  cout << "Content-Type: text/plain\n\n";
  cout << result << endl;

  return 0;
}

string JSCommunicator::print(Artwork artwork){
  string result, sep("*");
  result +=  to_string(artwork.getArtId()) + sep + artwork.getArtistInfo().author + sep + artwork.getArtistInfo().birthDeath + sep + artwork.getTitle() + sep + artwork.getArtStyle().technique + sep + artwork.getArtSetting().location + sep + artwork.getUrl() + sep + artwork.getArtStyle().form + sep + artwork.getArtStyle().type + sep + artwork.getArtStyle().school + sep + artwork.getArtSetting().timeframe + sep + artwork.getArtSetting().date + sep + to_string(artwork.getNumLikes()) + sep;

   return result;
}

//Precondition:
//Postcondition: Value of element is returned as a string
string JSCommunicator::getElement(string element, Cgicc &cgi){

  form_iterator itElement = cgi.getElement(element);
  string returnElement = **itElement;

  return returnElement;
}
