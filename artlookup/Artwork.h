//#using <iostream>
#include <string>

using namespace std;

#ifndef ARTWORK_H
#define ARTWORK_H

struct ArtistInfo {
  string author;
  string birthDeath;
  };

struct ArtSetting {
    string date;
    string location;
    string timeframe;
  };

struct ArtStyle {
    string technique;
    string school;
    string type;
    string form;
  };

// Uppercase class does not work
class Artwork{
  public:

    // Accessor Member Functions
    int getArtId();
    int getNumLikes();
    int getTitle();
    int getUrl();
    int getArtistInfo();
    int getArtSetting();
    int getArtStyle();

    void print();
    // Prints first three details about art
    // Testing purposes

    //Mutator
    void incrementLikes();
    
    Artwork();
    //Preconditions: All variables must come from the art table in the Team5 sql
    //database. The parameters are listed in the same order as the respective
    //columns
    //Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs

    Artwork(int artId, string author, string birthDeath, string title, string technique, string location, string url, string form, string type,
    string school,string timeframe, string date, int numLikes);
    //Preconditions: None
    //Postconditions: The member variable numLikes will be incremented

  private:
    int artId;
    int numLikes;
    string title;
    string url;
    ArtistInfo artistInfo;
    ArtSetting artSetting;
    ArtStyle artStyle;
};

#endif //ARTWORK_H
