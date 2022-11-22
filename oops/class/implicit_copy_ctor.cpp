#include <bits/stdc++.h>

using namespace std;
/*
Use case: Calling implict (compiler generated) copy constructor
*/
class Array{
public:
    int size;
    int *data;

    //default ctor
    Array(int sz) : size(sz), data(new int[size]){
        cout << "Array(int sz)\n";
    }
};

int main(){
    Array arr1(2);
    Array arr2 = arr1; //trying to create an object from another object inline. This calls copy constructor
    return 0;
}