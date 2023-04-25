#include <bits/stdc++.h>

using namespace std;
/*
Use case: Calling user coded copy constructor. This explains why we should use copy constructor. This also
demostrates how one could use copy ctor or assignment ctor for objects created on heap
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

    //overloaded assignment operator
    Array& operator=(const Array& other){
        cout << "overloaded assignment operator: Array& operator=(const Array& other)\n";

        //check self assignment
        if(&other == this){
            return *this;
        }

        if(size != other.size){ //deleting old memory
            if(data != NULL){
                delete[] data;
            }

            data = new int[other.size];
            size = other.size;
        }

        std::copy(other.data, (other.data+size), data);

        return *this;
    }

    ~Array(){
        cout << "~Array()\n";
        if(this->data != NULL){
            delete[] this->data;
        }
    }
};

int main(){
    Array *arr1 = new Array(2); //call default ctor
    
    Array *arr2 = new Array(*arr1); //calls copy ctor

    *arr2 = *arr1; //calls copy assignment operator

    //note that below way of assignment doesn't call copy assignment operator as to maintain the real purpose of pointer operation
    //arr2 = arr1;

    
    return 0;
}