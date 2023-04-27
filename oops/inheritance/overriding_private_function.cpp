#include <bits/stdc++.h>

using namespace std;

/*
 Usage: If Base::foo is marked private and Child::foo still can override it
 */

class Base{
private:
    virtual int foo(int i){ 
        cout << __PRETTY_FUNCTION__ << endl;
        return i;
    }
};

class Child : public Base{
public:
    //Note: Marking Child::foo virtual has also no effect
    int foo(int i){ 
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

int main(){
    unique_ptr<Base> base = make_unique<Child>(); //Base points to an object of Child
    //base->foo(5); //Build error. This is not calleable because foo in Base is private. This is a programmer/ desgin choice

    Child* child = static_cast<Child *>(base.get()); //Note that there is no standard way to downcast unique_ptr
    child->foo(5);

    return 0;
}