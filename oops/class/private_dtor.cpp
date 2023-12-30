#include <bits/stdc++.h>

using namespace std;

/*
Use case: Disallow instantiating class on stack
*/

class Base{
public:
    Base(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
private:
    ~Base(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    //Creating an object on stack
    Base base; //Dtor is private and hence object created on stack is not possible. Build error!

    return 0;
}