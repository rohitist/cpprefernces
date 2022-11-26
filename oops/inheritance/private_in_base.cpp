#include <bits/stdc++.h>
//Use case: When overriding function is private and we're accessing them in main()
using namespace std;

#define PRINT (cout << __PRETTY_FUNCTION__ << endl)

class Base{
    private:
    virtual void foo(){
        PRINT;
    }
};

class Derived : public Base{
    public:
    void foo(){
        PRINT;
    }
};

int main(){
    Base *b = new Derived();//b object has private function and we're trying to access in main() leading to error
    b->foo(); //build fails. Base::foo() is private in context of main()

    return 0;
}