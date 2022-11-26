#include <bits/stdc++.h>
//Use case: When overriding function is private in Derived
using namespace std;

#define PRINT (cout << __PRETTY_FUNCTION__ << endl)

class Base{
    public:
    virtual void foo(){
        PRINT;
    }
};

class Derived : public Base{
    private:
    void foo(){
        PRINT;
    }
};

int main(){
    Base *b = new Derived();
    b->foo(); //build passes. Base::foo() is public in context of main()

    return 0;
}