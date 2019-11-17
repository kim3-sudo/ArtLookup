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

int main(){
  Cgicc cgi; // Ajax object
  char *cstr;
  // Ajax object to receive info from web page
  form_iterator itSearch = cgi.getElement("searchVal");
  string searchVal = **itSearch;
  Artlookup artlookup;
  Query query;
  vector<Artwork> searchByTitle(artlookup.lookupSingleCommand(query.matchSingleCol(searchVal,"Title")));
  string colNames[13]; // FINISH ME!!!!!!!
  
  cout << "Content-Type: text/plain\n\n";








  //cout << results << endl;

  return 0;
}
