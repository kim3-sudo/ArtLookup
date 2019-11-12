#include "Artwork.h"

Artwork::Artwork()
{

}

/*Preconditions: All variables must come from the art table in the Team5 sql
  database. The parameters are listed in the same order as the respective
  columns
  Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs
*/
//This is very long MICHAELA!!! (Not mad just need your help)
Artwork::Artwork(int artIdFromDB, string titleFromDB, string urlFromDB, int numLikesFromDB, string authorFromDB, string birthDeathFromDB, int dateFromDB, string locationFromDB, string timeframeFromDB, string techniqueFromDB, string schoolFromDB, string typeFromDB, string formFromDB)
{
  artId = artIdFromDB;  //Alternate solution this->artId = artId
  title = titleFromDB;
  url = urlFromDB;
  numLikes = numLikesFromDB;

  ArtistInfo artistInfo{ authorFromDB, birthDeathFromDB };
  ArtSetting setting{ dateFromDB, locationFromDB, timeframeFromDB };
  ArtStyle style{ techniqueFromDB, schoolFromDB, typeFromDB, formFromDB };
}

/*Preconditions: None
  Postconditions: The member variable numLikes will be incremented
*/
void Artwork::incrementLikes()
{
  numLikes++;
}
