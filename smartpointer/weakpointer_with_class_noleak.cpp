/*
 * an example to show how to handle memory leak.
 *
 * Mother holds a strong reference (i.e. weak_ptr) of son
 * And son hold a strong reference (i.e. shared_ptr) of mother
 *
 * similarly,
 * mother holds a strong reference (i.e. weak_ptr) of daughter
 * and daughter holds a strong reference (i.e shared_ptr) of mother
 *
 * And in this case, each of the destructors are called
 */


#include <bits/stdc++.h>

using namespace std;

class son;
class daughter;

class mother{
public:
	mother(){}
	~mother(){ cout << "~mother()\n"; }

	void setSon(shared_ptr<son> s){ mySon = s; }
	void setDaughter(shared_ptr<daughter> d){ myDaughter = d; }
private:
	weak_ptr<son> mySon; // solution: weak_ptr is not used to construct object. it is only used to be constructed from shared_ptr
	weak_ptr<daughter> myDaughter; // solution
};

class son{
public:
	son(shared_ptr<mother> m) : myMother(m) {}
	~son(){ cout << "~son()\n"; }
private:
	shared_ptr<mother> myMother;
};

class daughter{
public:
	daughter(shared_ptr<mother> m) : myMother(m) {}
	~daughter(){ cout << "~daughter()\n"; }
private:
	shared_ptr<mother> myMother;
};

int main(){
	{
		shared_ptr<mother> mom = shared_ptr<mother>(new mother());
		shared_ptr<son> s = shared_ptr<son>(new son(mom));
		shared_ptr<daughter> d = shared_ptr<daughter>(new daughter(mom));

		mom->setSon(s);
		mom->setDaughter(d);
	}

	return 0;
}
