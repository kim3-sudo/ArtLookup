#include <iostream>
#include <string>

#include "Artwork.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#ifndef JSCOMMUNICATOR_H
#define JSCOMMUNICATOR_H

using namespace cgicc;

class JSCommunicator{
  public:
    //Preconditions: artwork must be an Artwork object
    //Postconditions: Returns artwork info delimited by * as a string
    string print(Artwork artwork);

    //Preconditions: element must be a string corresponding to an ajax element
    //sent from JavaScript. cgi is a Cgicc ajax object.
    //Postconditions: Returns the value of the ajax element as a string.
    string getElement(string element, Cgicc &cgi);
};

#endif //JSCOMMUNICATOR_H
