TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
SOURCE	= Artwork.cpp
HEADER	= Artwork.h ArtDBCommunicator.h
OUT	= Artwork
CC	 = g++
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14

all: TestArtApp

TestArtApp: $(TEST_OBJS)
	$(CC) -g $(TEST_OBJS) -L/usr/lib -o $(OUT) -L/usr/local/lib -lcgicc -lmysqlcppconn

ArtLookupTests.o: ArtLookupTests.cpp Artwork.h ArtLookup.h Query.h
	$(CC) $(FLAGS) ArtLookupTests.cpp $(CFLAGS)

Artwork.o: Artwork.cpp Artwork.h
	$(CC) $(FLAGS) Artwork.cpp $(CFLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

ArtLookup.o: ArtLookup.cpp ArtLookup.h ArtDBCommunicator.h Query.h
	$(CC) $(FLAGS) ArtLookup.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

clean:
	rm -f TestArtApp $(OUT)
