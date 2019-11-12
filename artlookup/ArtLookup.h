

// using sql::driver;
// using sql::mysql;
// using sql::Statement;
// using sql::ResultSet;
// using std::auto_ptr;

#include <string>
#include "Artwork"
#include <vector>

#ifndef ART_LOOKUP_H
#define ART_LOOKUP_H

class ArtLookup{
  public:
  	vector<Artwork> lookupAll(string search);
  	vector<Artwork> lookupSingle(string search, string colName);
  	// Maybe return array of size 10????
  	vector<Artwork> topLikedLookup();
  private:
};

#endif //ART_LOOKUP_H