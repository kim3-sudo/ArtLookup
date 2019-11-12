#include "ArtDBCommunicator.h"

//Default Constructor.
ArtDBCommunicator::ArtDBCommunicator(){

}

auto_ptr<Connection> ArtDBCommunicator::establishConnection(){

  Driver* driver = mysql::get_driver_instance();
  auto_ptr<Connection> con(driver->connect(url, user, pass));
  con->setSchema(database);

  return con;
}
