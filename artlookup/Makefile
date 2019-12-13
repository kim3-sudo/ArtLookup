TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
REAL_OBJS = ArtApp.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o JSCommunicator.o
ADD_MEMBER_OBJS = AddMember.o Member.o UserManager.o Artwork.o ArtDBCommunicator.o Query.o JSCommunicator.o
SIGNIN_MEMBER_OBJS = SigninMember.o Member.o UserManager.o Artwork.o ArtDBCommunicator.o Query.o JSCommunicator.o
LIKE_PHOTO_OBJS = LikePhoto.o ArtLookup.o JSCommunicator.o Query.o Artwork.o
#SOURCE	= Artwork.cpp
#HEADER	= Artwork.h ArtDBCommunicator.h
#OUT	= ArtApp
CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

all: ArtApp AddMember SigninMember PutCGI PutHTML
#all: ArtApp AddMember SigninMember LikePhoto PutCGI PutHTML
#all: ArtAppTest ArtApp AddMember TestArtApp PutCGI PutHTML

#ArtAppTest: $(ART_APP_TEST)
#	$(CC) $(ART_APP_TEST) -o ArtAppTest -L/usr/local/lib -lcgicc -lmysqlcppconn
#ArtAppTest.o: ArtLookupTests.cpp ArtLookup.h Query.h
#	$(CC) $(FLAGS) ArtAppTest.cpp $(CFLAGS)

ArtApp: $(REAL_OBJS)
	$(CC) $(REAL_OBJS) -o ArtApp -L/usr/local/lib $(SQL_FLAGS)

AddMember: $(ADD_MEMBER_OBJS)
	$(CC) $(ADD_MEMBER_OBJS) -o AddMember -L/usr/local/lib $(SQL_FLAGS)

SigninMember: $(SIGNIN_MEMBER_OBJS)
	$(CC) $(SIGNIN_MEMBER_OBJS) -o SigninMember -L/usr/local/lib $(SQL_FLAGS)

# LikePhoto: $(LIKE_PHOTO_OBJS)
# 	$(CC) $(LIKE_PHOTO_OBJS) -o LikePhoto -L/usr/local/lib $(SQL_FLAGS)

# TestArtApp: $(TEST_OBJS)
# 	$(CC) $(TEST_OBJS) -o testArtApp -L/usr/local/lib $(SQL_FLAGS)

ArtApp.o: ArtApp.cpp ArtLookup.h Query.h
	$(CC) $(FLAGS) ArtApp.cpp $(CFLAGS)

AddMember.o: AddMember.cpp Member.h UserManager.h
	$(CC) $(FLAGS) AddMember.cpp $(CFLAGS)

SigninMember.o: SigninMember.cpp UserManager.h
	$(CC) $(FLAGS) SigninMember.cpp $(CFLAGS)

# LikePhoto.o: LikePhoto.cpp ArtLookup.h JSCommunicator.h Query.h
# 	$(CC) $(FLAGS) LikePhoto.cpp $(CFLAGS)

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

UserManager.o: UserManager.cpp UserManager.h Query.h ArtDBCommunicator.h Member.h
	$(CC) $(FLAGS) UserManager.cpp $(CFLAGS)

JSCommunicator.o: JSCommunicator.cpp JSCommunicator.h Artwork.h
	$(CC) $(FLAGS) JSCommunicator.cpp $(CFLAGS)

PutCGI: ArtApp AddMember SigninMember
	chmod 757 ArtApp
	chmod 757 AddMember
	chmod 757 SigninMember
	cp ArtApp /usr/lib/cgi-bin/$(USER)_artAppSearch.cgi
	cp AddMember /usr/lib/cgi-bin/$(USER)_artAppAddMember.cgi
	cp SigninMember /usr/lib/cgi-bin/$(USER)_artAppSigninMember.cgi

	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp -R ../html /var/www/html/class/softdev/$(USER)/ArtApp

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/ArtApp

clean:
	rm -f ArtApp AddMember SigninMember $(OUT)
#	rm -f ArtAppTest ArtApp AddMember TestArtApp $(OUT)
