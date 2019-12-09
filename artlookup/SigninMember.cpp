//#include "Member.h"
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
  form_iterator itEmail = cgi.getElement("email"),itPassword = cgi.getElement("password");
  
  string email(**itEmail), password(**itPassword);
  //Member member(username,password,email);
  UserManager userManager;
  //Query query;
  //Artwork artwork;
  //JSCommunicator jSCommunicator;

  cout << "Content-Type: text/plain\n\n";

  if (userManager.canLogin(email,password)){
    // Log person in
    cout << "Valid";
  } else {
    cout << "Invalid";
  }


  // bool canAddMember(true);
  // if (userManager.isEmailTaken(member.getEmail())){
  //   // Add user to database
  //   canAddMember = false;
  //   cout << "Email" << endl;
  // }
  // if (userManager.isUsernameTaken(member.getUsername())){
  //   cout << "Username" << endl;
  //   canAddMember = false;
  // }
  // if (canAddMember){
  //   userManager.addMember(member);
  //   cout << "Success" << endl;
  // }
  
  return 0;
}











