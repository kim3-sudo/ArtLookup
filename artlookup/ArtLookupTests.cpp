
#include "ArtLookup.h"
#include "Query.h"
#include <iostream>

using std::cout

//using namespace std;

int main() {
  //Creates an art lookup to test
  ArtLookup testLookup = ArtLookup();
  Query query;
  
  // vector<Artwork> titleIsJokingCouple(testLookup.lookupSingle("Joking Couple", "Title"));
  vector<Artwork> titleIsAllegory(testLookup.lookupSingleCommand(query.matchSingleCol("Allegory","Title")));
  //vector<Artwork> titleIsJokingCouple(testLookup.lookupSingleCommand("SELECT * FROM art WHERE Title = 'Joking Couple';"));

  //cout << "Size: " << titleIsJokingCouple.size() << endl;
  /*
  cout << "PREDICTED OUTPUT" << endl;
  cout << "artId: 3" << endl;
  cout << "Author: AACHEN, Hans Von" << endl;
  cout << "Born-Diec: (b. 1552, Köln, d. 1615, Praha" << endl;
  cout << "Title: Joking Couple" << endl;
  cout << "Technique: Copperplate, 25 x 20 cm" << endl;
  cout << "Location: Kunsthistorisches Museum, Vien" << endl;
  cout << "URL: https://www.wga.hu/html/a/aachen/j_couple.jpg" << endl;
  cout << "Form: painting" << endl;
  cout << "Type: genre" << endl;
  cout << "School: German" << endl;
  cout << "Timeframe: 1601-1650" << endl;
  cout << "Date: " << endl;
  cout << "Likes: NULL" << endl;
  */
  cout << "\nACTUAL OUTPUT" << endl;

  //Artwork artwork = Artwork();
  Artwork artwork;

  // issues with unsigned in comparison for(uint i=0; i < titleIsJokingCouple.size(); i++){
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  //for(uint i=0; i < titleIsJokingCouple.size(); i++){
  //  artwork = titleIsJokingCouple.at(i);

  for(int i=0; i < titleIsAllegory.size(); i++){
    artwork = titleIsAllegory.at(i);

    cout << "PREDICTED OUTPUT" << endl;
    cout << "artId: " << artwork.getArtId() << endl;
    cout << "Author: " << artwork.getArtistInfo().author << endl;
    cout << "Born-Diec: " << artwork.getArtistInfo().birthDeath << endl;
    cout << "Title: " << artwork.getTitle() << endl;
    cout << "Technique: " << artwork.getArtStyle().technique << endl;
    cout << "Location: " << artwork.getArtSetting().location << endl;
    cout << "URL: " << artwork.getUrl() << endl;
    cout << "Form: " << artwork.getArtStyle().form << endl;
    cout << "Type: " << artwork.getArtStyle().type << endl;
    cout << "School: " << artwork.getArtStyle().school << endl;
    cout << "Timeframe: " << artwork.getArtSetting().timeframe << endl;
    cout << "Date: " << artwork.getArtSetting().date << endl;
    cout << "Likes: " << artwork.getNumLikes() << endl;
  }
  
}
