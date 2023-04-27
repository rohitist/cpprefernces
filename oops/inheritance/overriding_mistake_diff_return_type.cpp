#include <bits/stdc++.h>

using namespace std;

/*
 Usage: If Base::foo is marked virtual and Child::foo has same argument types but different return type
 */

class Base{
public:
    virtual void foo(int f){ //Solution of the build error: Remove the virtual keyword
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Child : public Base{
public:
    //Note: Marking Child::foo virtual has also no effect
    int foo(int i){ //Build error. It needs same return type as that is in Base::foo
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

int main(){
    unique_ptr<Base> base = make_unique<Child>(); //Base points to an object of Child

    return 0;
}