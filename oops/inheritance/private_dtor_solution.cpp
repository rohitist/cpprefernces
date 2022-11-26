#include <bits/stdc++.h>

using namespace std;

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
    //Creating an object on heap
    Base *base = new Base();
    //delete base; is still not allowed and dtor is private

    return 0;
}