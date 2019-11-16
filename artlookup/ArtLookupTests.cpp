//#include "ArtDBCommunicator"
//#include "Artwork.h"
#include "ArtLookup.h"
#include "Query.h"
#include <iostream>

using namespace std;

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

  // Unqualified Id
  //Artwork artwork = Artwork();
  Artwork artwork;

  // issues with unsigned in comparison for(uint i=0; i < titleIsJokingCouple.size(); i++){
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  //for(uint i=0; i < titleIsJokingCouple.size(); i++){
  //  artwork = titleIsJokingCouple.at(i);

  for(uint i=0; i < titleIsAllegory.size(); i++){
    artwork = titleIsAllegory.at(i);

    cout << "PREDICTED OUTPUT" << endl;


    //cout << "test: " << titleIsJokingCouple.at(i).artId << endl << endl;
    cout << "artId: " << artwork.artId << endl;
    cout << "Author: " << artwork.artistInfo.author << endl;
    cout << "Born-Diec: " << artwork.artistInfo.birthDeath << endl;
    cout << "Title: " << artwork.title << endl;
    cout << "Technique: " << artwork.artStyle.technique << endl;
    cout << "Location: " << artwork.artSetting.location << endl;
    cout << "URL: " << artwork.url << endl;
    cout << "Form: " << artwork.artStyle.form << endl;
    cout << "Type: " << artwork.artStyle.type << endl;
    cout << "School: " << artwork.artStyle.school << endl;
    cout << "Timeframe: " << artwork.artSetting.timeframe << endl;
    cout << "Date: " << artwork.artSetting.date << endl;
    cout << "Likes: " << artwork.numLikes << endl;
  }
  
}
