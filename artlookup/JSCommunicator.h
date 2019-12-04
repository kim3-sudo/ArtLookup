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
    string print(Artwork artwork);
    string getElement(string element, Cgicc &cgi);
};

#endif //JSCOMMUNICATOR_H
