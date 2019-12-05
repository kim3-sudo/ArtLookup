#include "UserManager.h"
#include "Member.h"
#include "string"
using namespace std;

int main(){
	Member member1("user1","password","email@email.com"),member2("mikki","p2","cam@kenyon.edu");
	UserManager userManager;
	if (userManager.isUsernameTaken(member1.getUsername())){
		cout << "Expected: True" << endl;
	} else {
		cout << "Unexpected: False" << endl;
	}
	if (userManager.isEmailTaken(member1.getEmail())){
		cout << "Expected: True" << endl;
	} else {
		cout << "Unexpected: False" << endl;
	}
	return 0;
}