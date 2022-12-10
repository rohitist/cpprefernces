#include <bits/stdc++.h>

using namespace std;

class Base { virtual void foo(){} };
class Derived : public Base {};

int main(){
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived*>(b); //dynamic_cast upon failure will return null pointer

    if(d)
        cout << "Casted to Derived\n";
    else
        cout << "Couldn't cast to Derived\n";

    

    return 0;
}