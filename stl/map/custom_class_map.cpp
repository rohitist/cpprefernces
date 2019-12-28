#include <bits/stdc++.h>

using namespace std;

class user{
public:
	int i;
	user(int val):i(val){}

	/*this is necessary for custom class. otherwise the compiler will report an error*/
	bool operator<(const user& usr) const{
		if(usr.i < this->i)
			return true;
		return false;
	}
};

int main(){
	map<user, int> mp;
	mp.insert(make_pair<user, int>(user(1), 1));
	return 0;
}
