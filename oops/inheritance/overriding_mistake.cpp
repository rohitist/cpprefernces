#include <bits/stdc++.h>

using namespace std;

/*
 Usage: A case of programmer error when programmer intended to override Base::foo with its own Child::foo but he mistakenly provided different signature
 i.e. different types of arguments. In this case, compiler will assume that Base::foo is never overriden and hence Base::foo will always be called in this case.
 */

class Base{
public:
    virtual void foo(int f){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Child : public Base{
public:
    void foo(float i){ //Solution is to keep argument type same as that are in Child::foo
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    unique_ptr<Base> base = make_unique<Child>(); //Base points to an object of Child
    base->foo(5); //But Base::foo will always be called
    base->foo(static_cast<int>(5)); //Even after static_cast to int, Base::foo will still be called because Child::foo cannot override Base::foo due to programmer mistake

    return 0;
}