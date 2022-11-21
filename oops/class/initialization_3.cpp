#include <iostream>

using namespace std;

//Below class arrangement is also called as COMPOSITION
class Animal{
public:
	Animal() {
		cout << "Animal()\n";
	}
};

class Dog{
public:
	Animal& an; //compilation failure

	Dog(){
		cout << "Dog()\n";
	}
};

int main(){
	Dog dog;

	return 0;
}
	
