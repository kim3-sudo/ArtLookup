#include "Member.h"
#include "UserManager.h"
#include "JSCommunicator.h"
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
  JSCommunicator jSCommunicator;
  string username = jSCommunicator.getElement("username",cgi), email = jSCommunicator.getElement("email",cgi), password = jSCommunicator.getElement("password",cgi);

  //form_iterator itUsername = cgi.getElement("username"),itEmail = cgi.getElement("email"),itPassword = cgi.getElement("password");
  //string username(**itUsername), email(**itEmail), password(**itPassword);
  //Member member(username,password,email); // constructor requires memberId now
  //cout << "Content-Type: text/plain\n\n";

  //Sends user data to JavaScript
  UserManager userManager;
  string returnToJs("");
  bool canAddMember(true);
  int numViolations(0);
  if (userManager.isEmailTaken(email)){
    // Add user to database
    returnToJs += "Email";
    numViolations++;
    canAddMember = false;
  }
  if (userManager.isUsernameTaken(username)){
    if (numViolations == 1){
      returnToJs += ";";
    }
    returnToJs += "Username";
    canAddMember = false;
  }
  if (canAddMember){
    userManager.addMember(username, email, password);
    // Maybe return nothing in this case?
    //returnToJs += "Success";
  }
  jSCommunicator.sendStringToJS(returnToJs);
  
  return 0;
}











