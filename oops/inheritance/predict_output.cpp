#include <iostream>
//Use case: Predit the output
class Base {
    virtual void method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();} //which method() will be called?
};

class A : public Base {
    void method() {std::cout << "from A" << std::endl;}
public:
    ~A() {method();}
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}

/*
Output: 

from A
from A
from Base
*/