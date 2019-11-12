// code to connect to the database
sql::Driver* driver = sql::mysql::get_driver_instance(); //loading in drivers
std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass)); //set up the connector
con->setSchema(database); //set the schema

return(con)
