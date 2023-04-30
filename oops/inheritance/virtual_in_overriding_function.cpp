#include <bits/stdc++.h>

using namespace std;

/*
Uase case: We don't need to use virtual keyword in the overriding function of the Derived class. But does it have any side effect, if we use it anyway?
*/

class Base{
public:
    virtual void foo(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Derived : public Base{
public:
    virtual void foo(){ //foo() is marked virtual. It has no meaning and has no side effect. Even the sizeof(Derived) remains same with or without being virtual
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    unique_ptr<Base> base = make_unique<Derived>();
    base->foo(); //Regardless of Derived::foo() marked as virtual, it will be called if the object is of type Derived.

    return 0;
}