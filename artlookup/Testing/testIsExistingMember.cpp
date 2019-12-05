#include "UserManager.h"
#include "Member.h"
#include "string"
using namespace std;

int main(){
	Member member1("user1","password","email@email.com"),member2("mikki","p2","cam@kenyon.edu");
	UserManager userManager;
	if (userManager.isExistingMember(member1)){
		cout << "Expected: True" << endl;
	} else {
		cout << "Unexpected: False" << endl;
	}
	if (userManager.isExistingMember(member2)){
		cout << "Unexpected: True" << endl;
	} else {
		cout << "Expected: False" << endl;
	}
	return 0;
}