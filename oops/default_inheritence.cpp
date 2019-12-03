#include <iostream>

using namespace std;

class animal{
public:
	virtual void bark() { cout << "animal bark()\n"; }
	virtual void eat() { cout << "animal eat()\n"; }
};

class dog : animal{
public:
	void bark() { cout << "dog bark()\n"; }
	void eat() { cout << "dog eat()\n"; }
};

int main(){
	animal *a;
	dog* d = new dog();
	d->bark();
	d->eat();

	return 0;
}
