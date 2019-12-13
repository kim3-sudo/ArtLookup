//File Name: SigninMember.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Receives email and password; Returns empty string if user not found; otherwise, returns
// string in form "memberId=" + matchingId + ";username=" + matchingUsername + ";"
//Last Changed: December 12, 2019

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
  string email = jSCommunicator.getElement("email",cgi), password = jSCommunicator.getElement("password",cgi);
  
  //cout << "Content-Type: text/plain\n\n";
  UserManager userManager;
  Member member(userManager.getLoginMember(email,password));
  string returnToJS("");

  if (userManager.canLogin(email,password)){
    //cout << "memberId=" << member.getId() << ";username=" << member.getUsername() << ";";
    // Try without ; at end
    returnToJS += "memberId=" + to_string(member.getId()) + "; username=" + member.getUsername() + ";";
  }
  jSCommunicator.sendStringToJS(returnToJS);

  return 0;
}



