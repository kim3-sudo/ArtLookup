#include "ArtLookup.h"
#include "Query.h"
#include "JSCommunicator.h"
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

  //Receive info from web page
  form_iterator itsearchVal = cgi.getElement("searchVal");
  string searchVal = **itsearchVal;
  //string searchVal = jSCommunicator.getElement("searchVal", cgi);
  form_iterator itsearchCategory = cgi.getElement("searchCategory");
  string searchCategory= **itsearchCategory;
  //string searchCategory = jSCommunicator.getElement("searchCategory", cgi);

  cout << "Content-Type: text/plain\n\n";
  string result = "Hello";
  result += searchVal + searchCategory;
  cout << result << endl;

  exit(1);

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
  cout << searchVal + searchCategory << endl;
  //Sends artwork data to JavaScript
  Artwork artwork;
  //string result = "";
  for (uint i = 0; i < searchResults.size(); i++){
    artwork = searchResults.at(i);
    result += jSCommunicator.print(artwork);
  }
  cout << result << endl;

  return 0;
}
