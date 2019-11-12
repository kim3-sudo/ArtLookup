//#using <iostream>
#using <string>

using namespace std;


#ifndef ARTWORK_H
#define ARTWORK_H

<<<<<<< HEAD
class ArtLookup{
=======
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
>>>>>>> c1ee1382e1b1bd59aee2d5c44c576020bd72265b
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
<<<<<<< HEAD

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


=======
    ArtistInfo artistInfo;
    ArtSetting artSetting;
    ArtStyle artStyle;
>>>>>>> c1ee1382e1b1bd59aee2d5c44c576020bd72265b
};

#endif ARTWORK_H
