TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o

REAL_OBJS = ArtApp.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o JSCommunicator.o

ADD_MEMBER_OBJS = AddMember.o Member.o UserManager.o Artwork.o ArtDBCommunicator.o Query.o JSCommunicator.o

SIGNIN_MEMBER_OBJS = SigninMember.o Member.o UserManager.o Artwork.o ArtDBCommunicator.o Query.o JSCommunicator.o

COMMENT_ON_PHOTO = CommentOnPhoto.o ArtDBCommunicator.o CommentManager.o JSCommunicator.o Artwork.o Query.o Comment.o

LIKE_PHOTO_OBJS = LikePhoto.o ArtLookup.o JSCommunicator.o Query.o Artwork.o ArtDBCommunicator.o Like.o LikeManager.o

VIEW_COMMENTS = ViewComments.o ArtDBCommunicator.o JSCommunicator.o CommentManager.o Query.o Comment.o Artwork.o Member.o UserManager.o

#SOURCE	= Artwork.cpp
#HEADER	= Artwork.h ArtDBCommunicator.h
#OUT	= ArtApp
CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = schultz4

all: ArtApp AddMember SigninMember CommentOnPhoto ViewComments LikePhoto PutCGI PutHTML

#ArtAppTest: $(ART_APP_TEST)
#	$(CC) $(ART_APP_TEST) -o ArtAppTest -L/usr/local/lib -lcgicc -lmysqlcppconn
#ArtAppTest.o: ArtLookupTests.cpp ArtLookup.h Query.h
#	$(CC) $(FLAGS) ArtAppTest.cpp $(CFLAGS)
# TestArtApp: $(TEST_OBJS)
# 	$(CC) $(TEST_OBJS) -o testArtApp -L/usr/local/lib $(SQL_FLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

ArtLookup.o: ArtLookup.cpp ArtLookup.h ArtDBCommunicator.h Query.h
	$(CC) $(FLAGS) ArtLookup.cpp $(CFLAGS)

Artwork.o: Artwork.cpp Artwork.h
	$(CC) $(FLAGS) Artwork.cpp $(CFLAGS)

JSCommunicator.o: JSCommunicator.cpp JSCommunicator.h Artwork.h
	$(CC) $(FLAGS) JSCommunicator.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

ArtApp.o: ArtApp.cpp ArtLookup.h JSCommunicator.h Query.h
	$(CC) $(FLAGS) ArtApp.cpp $(CFLAGS)

Member.o: Member.cpp Member.h
	$(CC) $(FLAGS) Member.cpp $(CFLAGS)

UserManager.o: UserManager.cpp UserManager.h Query.h ArtDBCommunicator.h
	$(CC) $(FLAGS) UserManager.cpp $(CFLAGS)

AddMember.o: AddMember.cpp Member.h UserManager.h
	$(CC) $(FLAGS) AddMember.cpp $(CFLAGS)

SigninMember.o: SigninMember.cpp UserManager.h
	$(CC) $(FLAGS) SigninMember.cpp $(CFLAGS)

Comment.o: Comment.cpp Comment.h
	$(CC) $(FLAGS) Comment.cpp $(CFLAGS)

CommentManager.o: CommentManager.cpp CommentManager.h Query.h Comment.h ArtDBCommunicator.h Member.h
	$(CC) $(FLAGS) CommentManager.cpp $(CFLAGS)

CommentOnPhoto.o: CommentOnPhoto.cpp CommentManager.h JSCommunicator.h
	$(CC) $(FLAGS) CommentOnPhoto.cpp $(CFLAGS)

ViewComments.o: ViewComments.cpp CommentManager.h JSCommunicator.h UserManager.h
	$(CC) $(FLAGS) ViewComments.cpp $(CFLAGS)

Like.o: Like.cpp Like.h
	$(CC) $(FLAGS) Like.cpp $(CFLAGS)

LikeManager.o: LikeManager.cpp LikeManager.h Like.h Query.h ArtDBCommunicator.h
	$(CC) $(FLAGS) LikeManager.cpp $(CFLAGS)

LikePhoto.o: LikePhoto.cpp ArtLookup.h JSCommunicator.h Query.h Like.h LikeManager.h
	$(CC) $(FLAGS) LikePhoto.cpp $(CFLAGS)

ArtLookupTests.o: ArtLookupTests.cpp ArtLookup.h
	$(CC) $(FLAGS) ArtLookupTests.cpp $(CFLAGS)

#Linking after compiling
ArtApp: $(REAL_OBJS)
	$(CC) $(REAL_OBJS) -o ArtApp -L/usr/local/lib $(SQL_FLAGS)

AddMember: $(ADD_MEMBER_OBJS)
	$(CC) $(ADD_MEMBER_OBJS) -o AddMember -L/usr/local/lib $(SQL_FLAGS)

SigninMember: $(SIGNIN_MEMBER_OBJS)
	$(CC) $(SIGNIN_MEMBER_OBJS) -o SigninMember -L/usr/local/lib $(SQL_FLAGS)

CommentOnPhoto: $(COMMENT_ON_PHOTO)
	$(CC) $(COMMENT_ON_PHOTO) -o CommentOnPhoto -L/usr/local/lib $(SQL_FLAGS)

ViewComments: $(VIEW_COMMENTS)
	$(CC) $(VIEW_COMMENTS) -o ViewComments -L/usr/local/lib $(SQL_FLAGS)

LikePhoto: $(LIKE_PHOTO_OBJS)
	$(CC) $(LIKE_PHOTO_OBJS) -o LikePhoto -L/usr/local/lib $(SQL_FLAGS)

PutCGI: ArtApp AddMember SigninMember CommentOnPhoto ViewComments LikePhoto
	chmod 757 ArtApp
	chmod 757 AddMember
	chmod 757 SigninMember
	chmod 757 CommentOnPhoto
	chmod 757 ViewComments
	chmod 757 LikePhoto
	cp ArtApp /usr/lib/cgi-bin/$(USER)_artAppSearch.cgi
	cp AddMember /usr/lib/cgi-bin/$(USER)_artAppAddMember.cgi
	cp SigninMember /usr/lib/cgi-bin/$(USER)_artAppSigninMember.cgi
	cp CommentOnPhoto /usr/lib/cgi-bin/$(USER)_artAppCommentPhoto.cgi
	cp ViewComments /usr/lib/cgi-bin/$(USER)_artAppGetCommentsPhoto.cgi
	cp LikePhoto /usr/lib/cgi-bin/$(USER)_artAppLikePhoto.cgi


	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp -R ../html /var/www/html/class/softdev/$(USER)/ArtApp

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/ArtApp

clean:
	rm -f ArtApp AddMember SigninMember CommentOnPhoto ViewComments LikePhoto $(OUT)
