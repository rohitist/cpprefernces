#include <bits/stdc++.h>

using namespace std;

class Basic{
public:
    void foo(int i){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void foo(int& i){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    int y = 5;
    Basic basic;
    basic.foo(5);

    //int& x = 5; This will not build as ref type needs to be binded with rvalue
    int& x = y; //correct way to initialize a ref type

    basic.foo(x); //Build error: This is still ambiguous as x stil cannot be binded to ref type

    //Summary: This overloading is not allowed in c++. For solution see function_overloading_ref_type_solution.cpp

    return 0;
}