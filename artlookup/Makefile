TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o
SOURCE	= Artwork.cpp
HEADER	= Artwork.h ArtDBCommunicator.h
OUT	= Artwork
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS   = 

all: TestArtApp

TestArtApp: $(TEST_OBJS)
	$(CC) -g $(TEST_OBJS) -L/usr/lib -o $(OUT) -L/usr/local/lib -lcgicc -lmysqlcppconn

ArtLookupTests.o: ArtLookupTests.cpp Artwork.h ArtLookup.h
	$(CC) $(FLAGS) ArtLookupTests.cpp -std=c11

Artwork.o: Artwork.cpp Artwork.h
	$(CC) $(FLAGS) Artwork.cpp -std=c11

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp -std=c11

ArtLookup.o: ArtLookup.cpp ArtLookup.h ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtLookup.cpp -std=c11

clean:
	rm -f TestArtApp $(OUT)
