//#include "ArtLookup.h"
//#include "Query.h"
#include "Member.h"
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
  form_iterator itUserName = cgi.getElement("username"),itEmail = cgi.getElement("email"),itPassword = cgi.getElement("password");
  string userName = **itUserName, email = **itEmail, password = **itPassword;
  Member member(username,password,email);
  UserManager userManager;
  //Query query;
  //Artwork artwork;
  //JSCommunicator jSCommunicator;

  cout << "Content-Type: text/plain\n\n";

  //Sends user data to JavaScript
  if (userManager.isValidMember(userName,password)){
    // Add user to database
    userManager.addMember(member);
    cout << "F" << endl;
  } else {
    cout << "T" << endl;
  }
  
  return 0;
}