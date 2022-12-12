#include <bits/stdc++.h>

using namespace std;

void foo(int val){
    cout << __PRETTY_FUNCTION__ << endl;
}

void foo(int* ptr){
    cout << __PRETTY_FUNCTION__ << endl;
}

int main(){
    foo(nullptr); //compiles fine. calls foo(int* ptr)

    return 0;
}