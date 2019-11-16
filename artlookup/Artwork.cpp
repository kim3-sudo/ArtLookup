//File Name: Artwork.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Data representation of a piece of art
//Last Changed: November 13, 2019

#include "Artwork.h"
#include <iostream>

using namespace std;

void Artwork::print(){
  cout << "Art Id: " << artId << endl;
  cout << "Title: " << title << endl;
  cout << "Num Likes: " << numLikes << endl;
}

Artwork::Artwork(){
  artId = -1;
  title = "Test";
  url = "";
  numLikes = 0;

  ArtistInfo artistInfo{ "", "" };
  ArtSetting setting{ "", "", "" };
  ArtStyle style{ "", "", "", "" };
}

Artwork::Artwork(int artIdFromDB, string authorFromDB, string birthDeathFromDB, string titleFromDB, string techniqueFromDB,
  string locationFromDB, string urlFromDB, string formFromDB, string typeFromDB, string schoolFromDB, string timeframeFromDB,
  string dateFromDB, int numLikesFromDB)
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
