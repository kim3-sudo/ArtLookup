//#include "ArtLookup.h"
#include "Query.h"
#include "UserManager.h"
#include <iostream>
// Maybe unnecessary
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
  // Ajax objects receive info from web page
  form_iterator itUserName = cgi.getElement("userName"),itPassword = cgi.getElement("password");
  string userName = **itUserName, password = **itPassword;
  UserManager userManager;
  Query query;
  //Artwork artwork;
  //JSCommunicator jSCommunicator;

  cout << "Content-Type: text/plain\n\n";

  //Sends user data to JavaScript
  if (userManager.isValidMember(userName,password)){
    // Add user to database
    // FINISH ME!!

    cout << "F" << endl;
  } else {
    cout << "T" << endl;
  }
  
  return 0;
}
