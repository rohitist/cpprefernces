#include <bits/stdc++.h>

using namespace std;

class Basic{
public:
    void foo(int& i){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void foo(const int& i){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    int y = 5;
    Basic basic;
    basic.foo(5); //This calls foo(const int& i) because it passes rvalue which is const type

    int& x = y;
    basic.foo(x); //This calls foo(int& i)

    return 0;
}