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

Class ArtLookup {
  public:
    ArtLookup();
    ArtLookup(int artId, string title, string url, int numLikes,
      string author, string birthDeath, int date, string location,
      string timeframe, string technique, string school, string type,
      string form);
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

#endif ARTWORK_H
