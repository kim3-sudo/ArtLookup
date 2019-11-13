#include "Artlookup.h"

vector<Artwork> Artlookup::lookupAll(string search){
	auto_ptr<Connection> con;
	con = establishConnection();

}
vector<Artwork> Artlookup::lookupSingle(string search, string colName){

}
// Maybe return array of size 10????
vector<Artwork> Artlookup::topLikedLookup(){

}