#include "JSCommunicator.h"
#include "CommentManager.h"
#include <iostream>
//#include <string>

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

// Change name of program to CommentOn.cpp
int main(){
    Cgicc cgi; // Ajax object
    JSCommunicator jSCommunicator;

    // Ajax objects receive info from web page
    string artId = jSCommunicator.getElement("artId",cgi);
    CommentManager commentManager;
    vector<Comment> matchingComments = commentManager.getComments(artId,"artwork");

    string commentInfoString(""), sep("*");

    for (int i=0;i<matchingComments.length();i++){
        if (i != 0){
            commentInfoString += sep;
        }
        commentInfoString += matchingComments[i].getComment() + sep + matchingComments[i].getUserId() + sep + to_string(matchingComments[i].getNumLikes());
    }

    // Sends the comments to javascript
    jSCommunicator.sendStringToJS(commentInfoString);
  return 0;
}
