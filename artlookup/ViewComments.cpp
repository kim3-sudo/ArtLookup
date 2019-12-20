#include "JSCommunicator.h"
#include "CommentManager.h"
#include "UserManager.h"
#include <iostream>
//#include <string>

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

// Returns string to js, starting with commentOnId, then comment, userid, numLikes repeated
// Separated by *

int main(){
    Cgicc cgi; // Ajax object
    JSCommunicator jSCommunicator;

    // Ajax objects receive info from web page
    string artId = jSCommunicator.getElement("artId",cgi);
    CommentManager commentManager;
    UserManager userManager;
    vector<Comment> matchingComments = commentManager.getComments(artId,"artwork");

    string commentInfoString(artId), sep("*"),username;

    for (uint i=0;i<matchingComments.size();i++){
        // if (i != 0){
        //     commentInfoString += sep;
        // }
        username = userManager.getUsernameById(matchingComments[i].getUserId());
        commentInfoString += sep + matchingComments[i].getComment() + sep + username + sep + to_string(matchingComments[i].getNumLikes());
    }

    // Sends the comments to javascript
    jSCommunicator.sendStringToJS(commentInfoString);
  return 0;
}
