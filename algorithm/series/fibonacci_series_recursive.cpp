#include <bits/stdc++.h>

//Use case: print the fibonacci series
using namespace std;

int fibonacci(int n){
    if(n <= 1)
        return n;
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    for(int i = 0; i < 9; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    return 0;
}