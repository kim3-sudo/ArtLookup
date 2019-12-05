#include "UserManager.h"
#include "Member.h"
using namespace std;

int main(){
	Member member('user1','password','email@email.com');
	UserManager userManager;
	if (userManager.isExistingMember(member)){
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	return 0;
}