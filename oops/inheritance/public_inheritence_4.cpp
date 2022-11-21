#include <iostream>

using namespace std;

class animal{
public:
	virtual void bark() { cout << "animal bark()\n"; }
	virtual void eat() { cout << "animal eat()\n"; }
};

class dog : public animal{
public:
	void bark() { cout << "dog bark()\n"; }
	void eat() { cout << "dog eat()\n"; }
	void wigTail() { cout << "dog::wigTail()\n"; }
};

int main(){
	animal *a;
	dog* d = new dog();

	a = d;// compiles fine
	a->bark();
	a->eat();
	a->wigTail(); //accessing function of dog

	return 0;
}
