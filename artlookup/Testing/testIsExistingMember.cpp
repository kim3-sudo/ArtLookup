#include "UserManager.h"
#include "Member.h"
#include "string"
using namespace std;

int main(){
	Member member("mikki","password","email@email.com");
	UserManager userManager;
	if (userManager.isExistingMember(member)){
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	return 0;
}