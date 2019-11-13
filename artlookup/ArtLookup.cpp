//File Name: ArtLookup.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Inherits from ArtDBCommunicator. Communicates specifically
//with art table in our database
//Last Changed: November 13, 2019

#include "ArtLookup.h"

vector<Artwork> Artlookup::lookupAll(string search){
	auto_ptr<Connection> con;
	con = establishConnection();

}
vector<Artwork> Artlookup::lookupSingle(string search, string colName){

}
// Maybe return array of size 10????
vector<Artwork> Artlookup::topLikedLookup(){

}