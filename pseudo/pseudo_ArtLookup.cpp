// DO NOT TRY TO COMPILE THIS CODE! IT WON'T WORK!

/* ######################## */
/* single or all art lookup */
/* ######################## */

// we'll need another string for column name, since this is also the *all* art lookup

vector<ArtLookup> ArtLookupDB::lookupAll(string search) {
    // code to connect to the database
    sql::Driver* driver = sql::mysql::get_driver_instance(); //loading in drivers
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass)); //set up the connector
    con->setSchema(database); //set the schema
  
    //creates a statement for our command
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    
    vector<Artwork> list;
    // select all from art where the cell value is like the search query
    stmt->execute("SELECT * FROM Art WHERE cell like '%"+search+"%'");
    // This will also need modified for the *all* art lookup
    std::auto_ptr< sql::ResultSet > resultsSet; //get the set of rows
    
    // a loop to pull the data out of the database
    do {
      res.reset(stmt->getResultSet());
      while (res->next()) {
          ArtLookup entry(
              resultsSet->getString("artID or some other name..."), //what should these be? These are column names, TBD...
              resultsSet->getString("ID"));
	  list.push_back(entry);

      }
    } while (stmt->getMoreResults());
    return list;
}
