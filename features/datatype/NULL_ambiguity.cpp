#include <bits/stdc++.h>

using namespace std;

void foo(int val){
    cout << __PRETTY_FUNCTION__ << endl;
}

void foo(int* ptr){
    cout << __PRETTY_FUNCTION__ << endl;
}

int main(){
    foo(NULL); //compiler error: call to foo() is ambiguous. see solution NULL_ambiguity_solution.cpp

    return 0;
}