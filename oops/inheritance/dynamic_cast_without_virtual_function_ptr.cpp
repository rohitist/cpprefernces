#include <bits/stdc++.h>

using namespace std;

class Base { };
class Derived : public Base {};

int main(){
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived*>(b); //Build Error: Base class is not having virtual function and hence it is not a polymorphic class

    if(d)
        cout << "Casted to Derived\n";
    else
        cout << "Couldn't cast to Derived\n";

    

    return 0;
}