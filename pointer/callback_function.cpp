//Use case: Implementation of callback function

/*
Callback function: A callback is any executable code that is passed as an argument to another code, which is expected to call back (execute) the argument at a given time.
*/

#include <iostream>

using namespace std;

typedef void (*fptr)();

void A(){
    cout << __PRETTY_FUNCTION__ << endl;
}

void B(fptr fp){
    (*fp)(); //calling back function pointer
}

int main(){
    fptr fp;
    fp = &A; //assigning the address of a function as a handler
    B(fp);

    return 0;
}