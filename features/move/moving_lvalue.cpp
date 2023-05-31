#include <bits/stdc++.h>

using namespace std;

/*
Use case: How to use std::move() to convert lvalue to rvalue.
std::move() is a way to transfer ownership from one unique_ptr holding the object to the another unique_ptr

See: https://stackoverflow.com/questions/3106110/what-is-move-semantics
*/

class Sample {
private:
    int *a;
public:
    Sample() : a(new int(5)) {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Sample(){
        cout << __PRETTY_FUNCTION__ << endl;
        delete a;
    }

    Sample(const Sample&& s){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void foo(){
        cout << __PRETTY_FUNCTION__ << " a: " << *a << endl;
    }
};

int main(){

    unique_ptr<Sample> sample(new Sample());
    //unique_ptr<Sample> sample1(sample); //This is a build error
    unique_ptr<Sample> sample1 = std::move(sample); //use std::move() to move lvalue and move ctor to move rvalue. so, std::move() casts lvalue to rvalue

	std::cout << "sample is " << (sample ? "not null\n" : "null\n");
	std::cout << "sample1 is " << (sample1 ? "not null\n" : "null\n");
    
    sample1->foo(); //OK
    sample->foo(); //acceesing sample after it is moved to sample1 is an undefined behaviour

    return 0;
}