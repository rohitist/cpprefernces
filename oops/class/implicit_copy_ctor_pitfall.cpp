#include <bits/stdc++.h>

using namespace std;
/*
Use case: Calling implict (compiler generated) copy constructor and the problem it hides
*/
class Array{
public:
    int size;
    int *data;

    //default ctor
    Array(int sz) : size(sz), data(new int[size]){
        cout << "Array(int sz)\n";
    }

    ~Array(){
        cout << "~Array()\n";
        if(this->data != NULL){
            delete[] this->data;
        }
    }
};

int main(){
    Array arr1(2);
    arr1.data[0] = 1;

    {
        Array arr2 = arr1; //trying to create an object from another object inline. This calls implicit copy constructor which leads to pointer assignment
    } //arr2 destroyed here and hence the pointer variable data destroyed contained in arr1 as well. Ouch!

    arr1.data[0] = 10; // Predict the output here
    return 0;
}