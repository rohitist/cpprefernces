#include <bits/stdc++.h>

using namespace std;
//Use case: Solition to: Can there be a pure vistrul destructor
class Base{
public:
    virtual ~Base() = 0;
};
Base::~Base(){
    cout << __PRETTY_FUNCTION__ << endl;
}

class Derived : public Base{
public:
    void print(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    Base *b = new Derived(); //compiler error. We can provide pure virtual dtor but have to provide a definition as shown above
    delete b;

    return 0;
}