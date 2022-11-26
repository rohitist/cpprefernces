#include <iostream>
//Use case: Private inheritence and accessing class from main()
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
	animal *a;
	dog* d = new dog();

	a = d; //compilation failure
	a->bark(); //trying to access private members of animal
	a->eat(); //trying to access private members of animal

	return 0;
}
