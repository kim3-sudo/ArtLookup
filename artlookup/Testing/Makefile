#TEST_OBJS = ArtLookupTests.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
#REAL_OBJS = ArtApp.o Artwork.o ArtDBCommunicator.o ArtLookup.o Query.o
TEST_IS_EXISTING = testIsExistingMember.o UserManager.o ArtDBCommunicator.o Member.o Query.o
ADD_MEMBER_OBJS = AddMember.o Member.o UserManager.o ArtDBCommunicator.o Query.o
CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

all: testIsExistingMember AddMember

testIsExistingMember: $(TEST_IS_EXISTING)
	$(CC) $(TEST_IS_EXISTING) -o testIsExistingMember -L/usr/local/lib $(SQL_FLAGS)

testIsExistingMember.o: testIsExistingMember.cpp UserManager.h
	$(CC) $(FLAGS) testIsExistingMember.cpp $(CFLAGS)

AddMember: $(ADD_MEMBER_OBJS)
	$(CC) $(ADD_MEMBER_OBJS) -o AddMember -L/usr/local/lib $(SQL_FLAGS)

AddMember.o: AddMember.cpp Member.h UserManager.h
	$(CC) $(FLAGS) AddMember.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

Member.o: Member.cpp Member.h
	$(CC) $(FLAGS) Member.cpp $(CFLAGS)

UserManager.o: UserManager.cpp UserManager.h Query.h ArtDBCommunicator.h Member.h
	$(CC) $(FLAGS) UserManager.cpp $(CFLAGS)

clean:
	rm -f testIsExistingMember AddMember $(OUT)
