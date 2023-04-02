#include <bits/stdc++.h>

using namespace std;

//Use case: Use of pointer to member access operator: .* and ->*

class AClass{
public:
    void foo() { cout << __PRETTY_FUNCTION__ << endl; }
    void bar() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main(){
    typedef void (AClass::* pointer)(); //declare a function pointer that points to nothing
    pointer somePointer = &AClass::foo;

    //Need an object to call somePointer
    AClass aClass;
    (aClass.*somePointer)(); //call somePointer to whatever it points to, using .* operator. dereference operator * is required because somePointer points to the address of AClass::foo()

    somePointer = &AClass::bar;//now lets point to bar
    AClass *aClass_1 = new AClass();
    (aClass_1->*somePointer)(); //call somePointer to whatever it points to, using .* operator. dereference operator * is required because somePointer points to the address of AClass::bar()

    return 0;
}



