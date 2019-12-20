VIEW_COMMENTS = ViewComments.o ArtDBCommunicator.o JSCommunicator.o CommentManager.o Query.o Comment.o Artwork.o
#SOURCE	= Artwork.cpp
#HEADER	= Artwork.h ArtDBCommunicator.h
#OUT	= ArtApp
CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

all: TestViewComments

TestViewComments: $(VIEW_COMMENTS)
	$(CC) $(VIEW_COMMENTS) -o TestViewComments -L/usr/local/lib $(SQL_FLAGS)

ArtApp.o: ArtApp.cpp ArtLookup.h Query.h
	$(CC) $(FLAGS) ArtApp.cpp $(CFLAGS)

AddMember.o: AddMember.cpp Member.h UserManager.h
	$(CC) $(FLAGS) AddMember.cpp $(CFLAGS)

SigninMember.o: SigninMember.cpp UserManager.h
	$(CC) $(FLAGS) SigninMember.cpp $(CFLAGS)

CommentOnPhoto.o: CommentOnPhoto.cpp CommentManager.h JSCommunicator.h
	$(CC) $(FLAGS) CommentOnPhoto.cpp $(CFLAGS)

ViewComments.o: ViewComments.cpp CommentManager.h JSCommunicator.h
	$(CC) $(FLAGS) ViewComments.cpp $(CFLAGS)

ArtLookupTests.o: ArtLookupTests.cpp ArtLookup.h
	$(CC) $(FLAGS) ArtLookupTests.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

Artwork.o: Artwork.cpp Artwork.h
	$(CC) $(FLAGS) Artwork.cpp $(CFLAGS)

ArtLookup.o: ArtLookup.cpp ArtLookup.h ArtDBCommunicator.h Query.h
	$(CC) $(FLAGS) ArtLookup.cpp $(CFLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

Member.o: Member.cpp Member.h
	$(CC) $(FLAGS) Member.cpp $(CFLAGS)

UserManager.o: UserManager.cpp UserManager.h Query.h ArtDBCommunicator.h
	$(CC) $(FLAGS) UserManager.cpp $(CFLAGS)

Comment.o: Comment.cpp Comment.h
	$(CC) $(FLAGS) Comment.cpp $(CFLAGS)

CommentManager.o: CommentManager.cpp CommentManager.h Query.h Comment.h ArtDBCommunicator.h Member.h
	$(CC) $(FLAGS) CommentManager.cpp $(CFLAGS)

JSCommunicator.o: JSCommunicator.cpp JSCommunicator.h Artwork.h
	$(CC) $(FLAGS) JSCommunicator.cpp $(CFLAGS)

clean:
	rm -f TestViewComments $(OUT)
