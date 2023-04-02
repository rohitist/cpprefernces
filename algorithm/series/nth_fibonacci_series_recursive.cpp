#include <bits/stdc++.h>

//Use case: print the nth number in the fibonacci series
using namespace std;

int fibonacci(int n){
    if(n <= 1)
        return n;
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    cout << fibonacci(9);
    cout << endl;

    return 0;
}