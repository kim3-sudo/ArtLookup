
#include <vector>
#include "ArtDBCommunicator.h"
#include "Artwork.h"

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup: public ArtDBCommunicator{
  public:
  	vector<Artwork> lookupGeneral(string search);
	//vector<Artwork> lookupSingle(string search, string colName);
	vector<Artwork> lookupSingleCommand(string command);
  	
  	// Maybe delete topLikedLookup altogether
  	//vector<Artwork> topLikedLookup();
	
	ArtLookup();
  	// Default Constructor
  private:
    vector<string> colNames;
};

#endif //ART_LOOKUP_H
