//File Name: ArtDBCommunicator.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: General class that can communicate with our database
//Last Changed: November 13, 2019

#include "ArtDBCommunicator.h"

//Default Constructor.
ArtDBCommunicator::ArtDBCommunicator(){

}

// Changed name from establishConnection
auto_ptr<Connection> ArtDBCommunicator::establishDBConnection(){

  Driver* driver = mysql::get_driver_instance();
  auto_ptr<Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);

  return con;
}
