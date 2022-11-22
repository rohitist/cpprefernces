#include <bits/stdc++.h>

using namespace std;
/*
Use case: Calling user coded copy constructor. This explains why we should use copy constructor
*/
class Array{
public:
    int size;
    int *data;

    //default ctor
    Array(int sz) : size(sz), data(new int[size]){
        cout << "Array(int sz)\n";
    }

    //copy ctor
    Array(const Array& other) : size(other.size), data(new int[other.size]){
        //std::copy performs deep copy
        std::copy(other.data, (other.data+other.size), data);
        cout << "copy ctor Array(const Array& other)\n";
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
        Array arr2 = arr1; //trying to create an object from another object inline. This calls explicit copy constructor which leads to deep copy
    } 

    arr1.data[0] = 10; // Predict the output here
    return 0;
}