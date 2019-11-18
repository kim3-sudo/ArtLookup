TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
REAL_OBJS = ArtApp.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
SOURCE	= Artwork.cpp
HEADER	= Artwork.h ArtDBCommunicator.h
OUT	= ArtApp
CC	 = g++
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = kim3

all: ArtApp TestArtApp PutCGI PutHTML

ArtApp: $(REAL_OBJS)
	$(CC) $(REAL_OBJS) -o $(OUT) -L/usr/local/lib -lcgicc -lmysqlcppconn

TestArtApp: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o testArtApp -L/usr/local/lib -lcgicc -lmysqlcppconn

ArtApp.o: ArtApp.cpp ArtLookup.h Query.h
	$(CC) $(FLAGS) ArtApp.cpp $(CFLAGS)

ArtLookupTests.o: ArtLookupTests.cpp ArtLookup.h
	$(CC) $(FLAGS) ArtLookupTests.cpp $(CFLAGS)

Artwork.o: Artwork.cpp Artwork.h
	$(CC) $(FLAGS) Artwork.cpp $(CFLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

ArtLookup.o: ArtLookup.cpp ArtLookup.h ArtDBCommunicator.h Query.h
	$(CC) $(FLAGS) ArtLookup.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

PutCGI: ArtApp
	chmod 757 ArtApp
	cp ArtApp /usr/lib/cgi-bin/$(USER)_artAppComplete.cgi

	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp -R ../html /var/www/html/class/softdev/$(USER)/ArtApp

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/ArtApp

clean:
	rm -f ArtApp TestArtApp $(OUT) testArtwork
