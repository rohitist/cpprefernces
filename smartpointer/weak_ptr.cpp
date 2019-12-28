#include<bits/stdc++.h>

/*weak_ptr is used to check the validity of the original shared_ptr assigned to it.
 *weak_ptr is not used to create object
 *weak_ptr doesn't take the ownership of the object
 *weak_ptr can be used by a user to check the existence of a pointer, which is shown in this example
 */

using namespace std;

class user{
public:
	user(int i) : val(i) { cout << "ctor user(int i)\n"; }
	~user() { cout << "~user()\n"; }

	int getCount() { return val; }
private:
	int val;
};

int main(){
	shared_ptr<user> usr = shared_ptr<user>(new user(1));
	weak_ptr<user> weak_usr = usr;

	if(weak_usr.expired())
		cout << "expired\n";
	else
		cout << "ok\n";

	cout << "resetting shared_ptr\n";

	usr.reset(new user(2));

	cout << "checking weak_ptr after reset\n";

	if(weak_usr.expired())
		cout << "expired\n";
	else
		cout << "ok\n";

	return 0;
}
