//#using <iostream>
#using <string>

using namespace std;

#ifndef ARTWORK_H
#define ARTWORK_H

struct ArtistInfo {
  string author;
  string birthDeath;

  };

struct ArtSetting {
    int date;
    string location;
    string timeframe;
  };

struct ArtStyle {
    string technique;
    string school;
    string type;
    string form;
  };

Class Artwork{
  public:
    Artwork();
    //Preconditions: All variables must come from the art table in the Team5 sql
    //database. The parameters are listed in the same order as the respective
    //columns
    //Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs


    ArtLookup(int artId, string author, string birthDeath, string title, string technique, string location, string url, string form, string type,
    string school,string timeframe, int date, int numLikes);
    //Preconditions: None
    //Postconditions: The member variable numLikes will be incremented

    //Mutator
    void incrementLikes();

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