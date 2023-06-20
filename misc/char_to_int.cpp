#include <bits/stdc++.h>

using namespace std;

int main(){
    char c = 'a';

    int c_int = c - '0'; //convert a char into its ASCII equivalent and store in an int

    cout << "char: " << c << " = " << c_int << endl;

    cout << "int: " << c_int << " = " << (char)('0' + c_int) << endl; //convert an int by stripping ASCII equivalency and store in an char

    return 0;
}