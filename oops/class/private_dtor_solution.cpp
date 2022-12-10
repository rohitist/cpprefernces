#include <bits/stdc++.h>

using namespace std;

class Base{
public:
    Base(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void cleanup(){
        delete this; //calling delete on this will also call destructor (irrespective of its private scope)
    }
private:
    ~Base(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    //Creating an object on heap
    Base *base = new Base();
    //delete base; is still not allowed and dtor is private
    base->cleanup();

    return 0;
}