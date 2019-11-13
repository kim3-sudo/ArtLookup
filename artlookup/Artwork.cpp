#include "Artwork.h"

Artwork::Artwork(){

}


Artwork::Artwork(int artIdFromDB, string authorFromDB, string birthDeathFromDB, string titleFromDB, string techniqueFromDB, 
  string locationFromDB, string urlFromDB, string formFromDB, string typeFromDB, string schoolFromDB, string timeframeFromDB, 
  int dateFromDB, int numLikesFromDB)
{
  artId = artIdFromDB;  //Alternate solution this->artId = artId
  title = titleFromDB;
  url = urlFromDB;
  numLikes = numLikesFromDB;

  artistInfo.author = authorFromDB;
  artistInfo.birthDeath = birthDeathFromDB;

  artSetting.date = dateFromDB;
  artSetting.location = locationFromDB;
  artSetting.timeframe = timeframeFromDB;

  artStyle.technique = techniqueFromDB;
  artStyle.school = schoolFromDB;
  artStyle.type = typeFromDB;
  artStyle.form = formFromDB;
}


void Artwork::incrementLikes()
{
  numLikes++;
}
