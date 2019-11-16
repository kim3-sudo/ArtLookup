
#include <vector>
#include "ArtDBCommunicator.h"
#include "Artwork.h"

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup: public ArtDBCommunicator{
  public:
  	vector<Artwork> lookupGeneral(string search);
    // Returns vector of Artwork results, comparing values in all columns to search

	  //vector<Artwork> lookupSingle(string search, string colName);
	  vector<Artwork> lookupSingleCommand(string command);
    // Returns vector of Artwork results given a valid SQL command
  	
  	// Maybe delete topLikedLookup altogether
    // We can call lookupSingleCommand(topLikedCommand) instead
  	// vector<Artwork> topLikedLookup();
	
	  ArtLookup();
  	// Default Constructor
  private:
    vector<string> colNames;
};

#endif //ART_LOOKUP_H
