#include "JSCommunicator.h"
#include "CommentManager.h"
#include <iostream>
#include <string>

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

int main(){
    Cgicc cgi; // Ajax object
    JSCommunicator jSCommunicator;
    // Ajax objects receive info from web page
    string artId = jSCommunicator.getElement("artId",cgi), comment = jSCommunicator.getElement("comment",cgi), commentOnType = jSCommunicator.getElement("commentOnType",cgi), memberId = jSCommunicator.getElement("memberId",cgi);
    CommentManager commentManager;
    commentManager.addComment(artId, commentOnType, comment, memberId);

    // ArtLookup artlookup;
    // // Looks for artwork that match the artId given by the javascript
    // vector<Artwork> likedArtworks = artlookup.lookupSingleCommand(artIdQuery);
    // Artwork likedArtwork = likedArtworks.at(0);

    // // Likes artwork and gets the new number of likes.
    // likedArtwork.incrementLikes();
    // int numLikes = likedArtwork.getNumLikes();
    // string updatedLikes = to_string(numLikes);

    // // Sends the new number of likes to javascript.
    jSCommunicator.sendStringToJS("");
  return 0;
}
