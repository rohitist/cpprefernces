#include <bits/stdc++.h>

using namespace std;

class Base { virtual void foo(){} }; //at least one virtual function is must for dynamic_cast to pass through build
class Derived : public Base {};

int main(){
    Derived derived;
    Base& base = derived;

    try{
        Derived &derived2 = dynamic_cast<Derived&>(base); 
        cout << "Casted to Derived\n";
    }catch(bad_cast& e){ //casting reference might lead to bad_cast exception. 
        cout << "Couldn't cast to Derived\n";
        e.what();
    }

    return 0;
}