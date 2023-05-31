#include <bits/stdc++.h>

using namespace std;

/*
Use case: Program to understand the difference between a lvalue and rvalue
*/

void foo(string&& r){
    cout << __PRETTY_FUNCTION__ << endl;
}

void foo(string& r){
    cout << __PRETTY_FUNCTION__ << endl;
}

int main(){
    //comment below function implementation and the program will fail to compile
    foo("hello world"); //calls foo() because arg is converted from const char* to std::string. This is called rvalue or temporary

    string s = "hello world";
    foo(s); // this calls foo() because s is a lvalue. i.e., s has valid memory location

    return 0;
}