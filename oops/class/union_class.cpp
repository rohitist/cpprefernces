#include <bits/stdc++.h>

//example of class of type union
using namespace std;

union union_class{
    //all members of a union class is public by defualt just like struct class
    union_class(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~union_class(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    union_class u;

    return 0;
}