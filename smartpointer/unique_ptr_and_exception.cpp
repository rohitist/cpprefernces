#include <bits/stdc++.h>


/*
Use case: Benefit of using smart pointer over raw pointer when an exception is followed by.
*/
using namespace std;

class Sample {
public:
    Sample(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Sample(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void foo(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){

    try{
        unique_ptr<Sample> sample = make_unique<Sample>(); // memory clean up is taken care even if there is an exception at later stage
        throw std::bad_alloc();
    }
    catch(...){

    }

    try{
        Sample* sample = new Sample(); //memory leak
        throw std::bad_alloc();
    }
    catch(...){

    }

    return 0;
}