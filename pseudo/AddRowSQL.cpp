// DO NOT TRY TO COMPILE THIS CODE! IT WON'T WORK!

/* ######################## */
/*       add sql entry      */
/* ######################## */

/*
take in member object, like comments, likes, or members
have some standard code to connect to the database and create a statement
there shouldn't be much to error check for, unless we WANT to check for SQL insertion attacks
statement to execute the SQL code
    INSERT INTO TableName(column, column, ...) VALUES ('"+object.value+"', '"+object.value+"', ...);
*/

void db_communicator::addEntry(another object){
    sql::Driver* driver = sql::mysql::get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(address /*the address of the picture*/, DBUsername /*the username of the database accessor*/, password /*the password for the accessor's account*/));
    
    //set the connector to use the schema DBName
    con->setSchema(DBName);
    
    std::auto_ptr<sql::Statement> stmt(con->createStatement());
    if(we want to check for an injection attack?){
        do something...;
    }
    // actually execute the SQL code
    stmt->execute("INSERT INTO TableName(column, column, ...) VALUES ('"+object.value+"', '"+object.value+"', ...);");
}
