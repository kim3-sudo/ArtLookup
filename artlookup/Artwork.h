//#using <iostream>
#using <string>

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;


#ifndef ARTWORK_H
#define ARTWORK_H

Class ArtLookup
{
  public:
    ArtLookup();
    ArtLookup(int artId, string title, string url, int numLikes, string author, string birthDeath, int date, string location, string timeframe, string technique, string school, string type, string form);

    int artId;
    int numLikes;
    string title;
    string url;

    struct ArtistInfo
    {
      string author;
      string birthDeath;
    };
    struct ArtSetting
    {
      int date;
      string location;
      string timeframe;
    };
    struct ArtStyle
    {
      string technique;
      string school;
      string type;
      string form;
    };


    //Mutator
    void incrementLikes();

  private:


};

#endif /* ARTWORK_H */
