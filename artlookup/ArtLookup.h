
#include <vector>
#include "ArtDBCommunicator.h"
#include "Artwork.h"

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup: public ArtDBCommunicator{
  public:
  	vector<Artwork> lookupAll(string search);
  	vector<Artwork> lookupSingle(string search, string colName);
  	Artwork[10] topLikedLookup();
  private:
    vector<string> columnNames;
};

#endif //ART_LOOKUP_H
