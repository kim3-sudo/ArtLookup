#include "ArtDBCommunicator"
#include "Artwork.h"
#include "ArtLookup.h"

#include <iostream>

using namespace std;

int main() {
  //Creates an art lookup to test
  ArtLookup testLookup = ArtLookup();

  vector<Artwork> titleIsJokingCouple testLookup.lookupSingle("Joking Couple", "Title");

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

  cout << "\nACTUAL OUTPUT" << endl;
  Artwork artwork = Artwork();
  string colNames[13]= {"artId","Author","Born-Diec","Title","Technique","Location","URL","Form", "Type", "School", "Timeframe", "Date", "Likes"};
  for(i=0; i<titleIsJokingCouple.size(); i++){
    artwork = titleisJoking.at(i);
    cout << "PREDICTED OUTPUT" << endl;
    cout << "artId: " << artwork.artId << endl;
    cout << "Author: " << artwork.ArtistInfo.author << endl;
    cout << "Born-Diec: " << artwork.ArtistInfo.birthDeath << endl;
    cout << "Title: " << artwork.title << endl;
    cout << "Technique: " << artwork.ArtStyle.technique << endl;
    cout << "Location: " << artwork.ArtSetting.location << endl;
    cout << "URL: " << artwork.url << endl;
    cout << "Form: " << artwork.ArtStyle.form << endl;
    cout << "Type: " << artwork.ArtStyle.type << endl;
    cout << "School: " << artwork.ArtStyle.school << endl;
    cout << "Timeframe: " << artwork.ArtSetting.Timeframe << endl;
    cout << "Date: " << artwork.Artsetting.date << endl;
    cout << "Likes: " << artwork.numLikes << endl;
  }



}
