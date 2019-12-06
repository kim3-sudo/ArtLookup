TEST_CAN_LOGIN = TestCanLogin.o UserManager.o ArtDBCommunicator.o Member.o Query.o
CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

all: TestCanLogin

TestCanLogin: $(TEST_CAN_LOGIN)
	$(CC) $(TEST_CAN_LOGIN) -o testIsExistingMember -L/usr/local/lib $(SQL_FLAGS)

TestCanLogin.o: TestCanLogin.cpp UserManager.h
	$(CC) $(FLAGS) TestCanLogin.cpp $(CFLAGS)

Query.o: Query.cpp Query.h
	$(CC) $(FLAGS) Query.cpp $(CFLAGS)

ArtDBCommunicator.o: ArtDBCommunicator.cpp ArtDBCommunicator.h
	$(CC) $(FLAGS) ArtDBCommunicator.cpp $(CFLAGS)

Member.o: Member.cpp Member.h
	$(CC) $(FLAGS) Member.cpp $(CFLAGS)

UserManager.o: UserManager.cpp UserManager.h Query.h ArtDBCommunicator.h Member.h
	$(CC) $(FLAGS) UserManager.cpp $(CFLAGS)

clean:
	rm -f TestCanLogin $(OUT)
