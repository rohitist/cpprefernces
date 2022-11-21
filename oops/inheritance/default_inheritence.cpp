#include <iostream>

using namespace std;

class animal{
public:
	virtual void bark() { cout << "animal bark()\n"; }
	virtual void eat() { cout << "animal eat()\n"; }
};

class dog : animal{ //Default inheritance is also private inheritence
public:
	void bark() { cout << "dog bark()\n"; }
	void eat() { cout << "dog eat()\n"; }
};

int main(){
	//Default inheritance works with object of same class
	dog* d = new dog();
	d->bark();
	d->eat();

	return 0;
}
