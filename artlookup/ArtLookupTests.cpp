#include "ArtDBCommunicator"
#include "Artwork.h"
#include "ArtLookup.h"

using namespace std;

int main() {
  //Creates an art lookup to test
  ArtLookup testLookup = ArtLookup();

  vector<Artwork> titleIsJokingCouple testLookup.lookupSingle("Joking Couple", "Title");


}
