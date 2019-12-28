/*
 * an example to show memory leak.
 *
 * Mother holds a strong reference (i.e. shared_ptr) of son
 * And son hold a strong reference (i.e. shared_ptr) of mother - This is cyclic reference
 *
 * similarly,
 * mother holds a strong reference (i.e. shared_ptr) of daughter
 * and daughter holds a strong reference (i.e shared_ptr) of mother - This is cyclic reference
 *
 * And in this case, none of the destructors are called
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
	shared_ptr<son> mySon; // problem
	shared_ptr<daughter> myDaughter; // problem
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
		shared_ptr<mother> mom = shared_ptr<mother>(new mother()); // it increases the ref cnt of mom to 1
		//cout << mom.use_count() << endl;
		shared_ptr<son> s = shared_ptr<son>(new son(mom)); //shared_ptr within son will increase the ref count of mom to 2
		//cout << mom.use_count() << endl;
		shared_ptr<daughter> d = shared_ptr<daughter>(new daughter(mom)); //shared_ptr within daughter will increase the ref count of mom to 3
		//cout << mom.use_count() << endl;

		/*below statement caused the mom to hold the shared_ptr of son. 
 		 *son goes out of scope before mother but this wont allow destruction of son before mother. 
                 *and hence mother will also not be destroyed. 
	 	 */
		mom->setSon(s); //this also causes ref count of s to increase to 2

		/*below statement caused the mom to hold the shared_ptr of daughter. 
 		 *daughter goes out of scope before mother but this wont allow destruction of daughter before mother. 
                 *and hence mother will also not be destroyed. 
	 	 */
		mom->setDaughter(d); //this also causes ref count of d to increase to 2

	}

	return 0;
}
