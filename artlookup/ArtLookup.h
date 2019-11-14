
#include <vector>
#include "ArtDBCommunicator.h"
#include "Artwork.h"

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup: public ArtDBCommunicator{
  public:
  	vector<Artwork> lookupAll(string search);
  	vector<Artwork> lookupSingle(string search, string colName);

  	// You cannot return an array; you can only return a pointer to an array
  	vector<Artwork> topLikedLookup();
  private:
    vector<string> columnNames;
};

#endif //ART_LOOKUP_H
