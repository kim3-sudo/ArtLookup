//File Name: JSCommunicator.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Sends output and gets input to and from JavaScript through Ajax
//Last Changed: December 3, 2019

#include "JSCommunicator.h"

string JSCommunicator::printArtwork(Artwork artwork){
  string result, sep("*");
  result +=  to_string(artwork.getArtId()) + sep + artwork.getArtistInfo().author + sep + artwork.getArtistInfo().birthDeath + sep + artwork.getTitle() + sep + artwork.getArtStyle().technique + sep + artwork.getArtSetting().location + sep + artwork.getUrl() + sep + artwork.getArtStyle().form + sep + artwork.getArtStyle().type + sep + artwork.getArtStyle().school + sep + artwork.getArtSetting().timeframe + sep + artwork.getArtSetting().date + sep + to_string(artwork.getNumLikes()) + sep;

   return result;
}


string JSCommunicator::getElement(string element, Cgicc &cgi){

  form_iterator itElement = cgi.getElement(element);
  string returnElement = **itElement;

  return returnElement;
}

void sendStringToJS(string stringForJS){
  cout << stringForJS;
}
