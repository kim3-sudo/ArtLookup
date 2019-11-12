OBJS	= Artwork.o
SOURCE	= Artwork.cpp
HEADER	= Artwork.h ArtDBCommunicator.h
OUT	= Artwork
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Artwork.o: Artwork.cpp
	$(CC) $(FLAGS) Artwork.cpp -std=c11


clean:
	rm -f $(OBJS) $(OUT)
