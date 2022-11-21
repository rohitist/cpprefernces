#include <iostream>

using namespace std;

class animal{
public:
	virtual void bark() { cout << "animal bark()\n"; }
	virtual void eat() { cout << "animal eat()\n"; }
	virtual void smell() { cout << "animal smell()\n"; }
};

class dog : public animal{
public:
	void bark() { cout << "dog bark()\n"; }
	void eat() { cout << "dog eat()\n"; }
};

int main(){
	animal *a;
	dog* d = new dog();

	a = d;// compiles fine
	a->bark();
	a->eat(); 
	a->smell(); 

	return 0;
}
