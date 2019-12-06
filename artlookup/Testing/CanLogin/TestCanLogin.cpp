#include "UserManager.h"
#include "string"
using namespace std;

int main(){
	Member member1("user1","password","email@email.com"),member2("mikki","p2","cam@kenyon.edu"), member3("tim","password","sorry@notsorry.com");
	UserManager userManager;
	if (userManager.canLogin(member1.getEmail(),member1.getPassword())){
		cout << "Expected: True" << endl;
	} else {
		cout << "Unexpected: False" << endl;
	}
	if (userManager.canLogin(member2.getEmail(),member2.getPassword())){
		cout << "Unexpected: True" << endl;
	} else {
		cout << "Expected: False" << endl;
	}
	if (userManager.canLogin(member3.getEmail(),member3.getPassword())){
		cout << "Unexpected: True" << endl;
	} else {
		cout << "Expected: False" << endl;
	}
	return 0;
}