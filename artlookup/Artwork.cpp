//File Name: Artwork.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Data representation of a piece of art
//Last Changed: November 12, 2019

#include "Artwork.h"

//Default constructor artId is set to -1 all other variables are set to
//appropriate 'empty' values
Artwork::Artwork(){
  artId = -1;
  title = "";
  url = ""
  numLikes = 0;

  ArtistInfo artistInfo{ "", "" };
  ArtSetting setting{ 0, "", "" };
  ArtStyle style{ "", "", "", "" };
}

/*
  Preconditions: All variables must come from the art table in the Team5 sql
  database. The parameters are listed in the same order as the respective
  columns
  Postconditions: Relevant data is stored in member variables including ArtistInfo, ArtSetting and ArtStyle structs
*/
//This is very long MICHAELA!!! (Not mad just need your help)
<<<<<<< HEAD
Artwork::Artwork(int artIdFromDB, string titleFromDB, string urlFromDB, int numLikesFromDB, string authorFromDB, string birthDeathFromDB, int dateFromDB, string locationFromDB, string timeframeFromDB, string techniqueFromDB, string schoolFromDB, string typeFromDB, string formFromDB){
=======
Artwork::Artwork(int artIdFromDB, string titleFromDB, string urlFromDB, 
  int numLikesFromDB, string authorFromDB, string birthDeathFromDB, int dateFromDB, 
  string locationFromDB, string timeframeFromDB, string techniqueFromDB, string schoolFromDB, string typeFromDB, string formFromDB)
{
>>>>>>> c1ee1382e1b1bd59aee2d5c44c576020bd72265b
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

/*
  Preconditions: None
  Postconditions: The member variable numLikes will be incremented
*/
void Artwork::incrementLikes(){
  numLikes++;
}
