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
    vector<Base> vec1(5);

    Derived derived1;
    Derived derived2;

    vec1[0] = derived1;
    vec1[1] = derived2;

    vec1[0].foo(); //object slicing: information about Derived::foo() is lost
    vec1[1].foo(); //object slicing: information about Derived::foo() is lost

    cout << "Solution of object slicing: use pointer\n";

    vector<Base *> vec2(5);

    vec2[0] = &derived1;
    vec2[1] = &derived2;

    vec2[0]->foo(); //No object slicing
    vec2[1]->foo(); //No object slicing


    return 0;
}