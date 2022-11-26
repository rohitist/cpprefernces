#include <bits/stdc++.h>

using namespace std;
//Use case: Can there be a pure vistrul destructor
class Base{
public:
    virtual ~Base() = 0;
};

class Derived : public Base{
public:
    void print(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    Base *b = new Derived(); //compiler error. We can provide pure virtual dtor but have to provide a definition as shown in pure_virtual_dtor_solution.cpp

    return 0;
}