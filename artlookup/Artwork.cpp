
//File Name: Artwork.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Data representation of a piece of art
//Last Changed: November 13, 2019

#include "Artwork.h"

Artwork::Artwork(){
<<<<<<< HEAD
  artId = -1;
  title = "";
  url = "";
  numLikes = 0;

  ArtistInfo artistInfo{ "", "" };
  ArtSetting setting{ 0, "", "" };
  ArtStyle style{ "", "", "", "" };
=======

>>>>>>> d965691d567d6566cb1338c8cb348b28f53094b8
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
