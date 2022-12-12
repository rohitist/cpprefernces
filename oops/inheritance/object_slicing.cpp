#include <bits/stdc++.h>

using namespace std;

class Base{
public:
    virtual void foo(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Derived : public Base{
    void foo(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    Derived derived;
    Base base = derived;//object slicing occurs with plain data type and information in Derived is lost while copying it to Base

    base.foo();

    Base *base_ptr = &derived;//This is the solution to the object slicing. Use pointer
    base_ptr->foo();

    return 0;
}