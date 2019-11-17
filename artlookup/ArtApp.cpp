#include "ArtLookup.h"
#include "Query.h"
#include <iostream>
// Maybe unnecessary
#include <string>


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
};

//string intToStr(int num);

int main(){
  Cgicc cgi; // Ajax object
  //char *cstr;
  // Ajax object to receive info from web page
  form_iterator itSearch = cgi.getElement("searchVal");
  string searchVal = **itSearch;
  ArtLookup artLookup;
  Query query;
  vector<Artwork> searchByTitle(artLookup.lookupSingleCommand(query.matchSingleCol(searchVal,"Title")));
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"},result("Content-Type: text/plain\n\n");

  Artwork artwork;
  JSCommunicator jSCommunicator;
  for (uint i=0;i<searchByTitle.size();i++){
    artwork = searchByTitle.at(i);
    result += jSCommunicator.print(artwork);
  }
  cout << result;

  return 0;
}

string JSCommunicator::print(Artwork artwork){
  string result, sep(" * ");
  result += sep + to_string(artwork.getArtId()) + sep + artwork.getArtistInfo().author + sep + artwork.getArtistInfo().birthDeath + sep + artwork.getTitle() + sep + artwork.getArtStyle().technique + sep + artwork.getArtSetting().location + sep + artwork.getUrl() + sep + artwork.getArtStyle().form + sep + artwork.getArtStyle().type + sep + artwork.getArtStyle().school + sep + artwork.getArtSetting().timeframe + sep + artwork.getArtSetting().date + sep + to_string(artwork.getNumLikes());
  // For some reason date not sending

  
   return result;
}
