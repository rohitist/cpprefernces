#include <iostream>

using namespace std;

class animal{
public:
	virtual void bark() { cout << "animal bark()\n"; }
	virtual void eat() { cout << "animal eat()\n"; }
};

class dog : private animal{ //private inheritence means all members of animal is private to dog
public:
	void bark() { cout << "dog bark()\n"; }
	void eat() { cout << "dog eat()\n"; }
};

int main(){
	//Private inheritence works for same class. Compiles fine
	dog* d = new dog();

	d->bark();
	d->eat();

	return 0;
}
