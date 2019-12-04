//#include "ArtLookup.h"
//#include "Query.h"
#include "Member.h"
#include "UserManager.h"
#include <iostream>

#include <string> //so that it's not a cstring

// Stuff for Ajax
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// Fix later
using namespace cgicc;
using std::cout;

int main(){
  Cgicc cgi; // Ajax object
  // Ajax objects receive info from web page
  form_iterator itUsername = cgi.getElement("username"),itEmail = cgi.getElement("email"),itPassword = cgi.getElement("password");
  
  string username(**itUsername), email(**itEmail), password(**itPassword);
  Member member(username,password,email);
  UserManager userManager;
  //Query query;
  //Artwork artwork;
  //JSCommunicator jSCommunicator;

  cout << "Content-Type: text/plain\n\n";

  //Sends user data to JavaScript
  if (userManager.isExistingMember(member)){
    // Add user to database
    userManager.addMember(member);
    cout << "F" << endl;
  } else {
    cout << "T" << endl;
  }
  
  return 0;
}
