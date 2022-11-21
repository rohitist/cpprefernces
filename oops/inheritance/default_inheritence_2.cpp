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
	animal *a;
	dog* d = new dog();

	a = d; //compilation failure due to private/ default inheritence. see public_inheritence.cpp
	a->bark();
	a->eat();

	return 0;
}
