//#using <iostream>
#using <string>

using namespace std;


#ifndef ARTWORK_H
#define ARTWORK_H

class ArtLookup{
  public:
    ArtLookup();
    ArtLookup(int artId, string title, string url, int numLikes, string author, string birthDeath, int date, string location, string timeframe, string technique, string school, string type, string form);

    int artId;
    int numLikes;
    string title;
    string url;

    struct ArtistInfo{
      string author;
      string birthDeath;
    };
    struct ArtSetting{
      int date;
      string location;
      string timeframe;
    };
    struct ArtStyle{
      string technique;
      string school;
      string type;
      string form;
    };


    //Mutator
    void incrementLikes();

  private:


};

#endif ARTWORK_H
