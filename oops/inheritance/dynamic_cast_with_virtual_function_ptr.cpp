#include <bits/stdc++.h>

using namespace std;

class Base { 
public:
    virtual void foo(){ cout << __PRETTY_FUNCTION__ << endl; } 
};
class Derived : public Base {
public:
    void foo() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main(){
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived*>(b); //dynamic_cast upon failure will return null pointer

    if(d){
        cout << "Casted to Derived\n";
        d->foo();
    }
    else{
        cout << "Couldn't cast to Derived\n";
    }

    

    return 0;
}