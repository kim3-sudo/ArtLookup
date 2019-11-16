//File Name: ArtDBCommunicator.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: General class that can communicate with our database
//Last Changed: November 13, 2019

#include "ArtDBCommunicator.h"

//Default Constructor.
// ArtDBCommunicator::ArtDBCommunicator(){

// }

// Changed name from establishConnection
std::unique_ptr<sql::Connection> ArtDBCommunicator::establishDBConnection(){
  sql::Driver* driver = sql::mysql::get_driver_instance();
  std::unique_ptr<sql::Connection> con(driver->connect(address, DBUsername, password));
  con->setSchema(DBName);
  return con;
}
