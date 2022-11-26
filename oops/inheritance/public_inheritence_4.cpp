#include <iostream>
//Use case: This program demostrates that the compilation will fail if no virtual function is defined in case of inheritence

using namespace std;
#define PRINT_FUNCTION (cout << __PRETTY_FUNCTION__ << endl)

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
	a->bark(); //build fine
	a->eat(); //build fine
	a->wigTail(); //Build fail because there is no virtual function in Parent class

	return 0;
}
