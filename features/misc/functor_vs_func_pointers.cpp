#include <bits/stdc++.h>

/*
functors can access the state of the object 

function pointer is stateless and it can only contain internal state. i.e. two invocations have independent states unless shared by global or static variable

https://stackoverflow.com/questions/37635300/function-pointer-vs-functors-in-c
*/

using namespace std;

struct add_x{
    add_x(int val) : x(val) {}
    int operator()(int y){ //in a functor, operator() is overloaded
        return (x + y);
    }
private:
    int x;
};

int main(){
    add_x add42(42); //functor hold a state of 48
    int i = add42(8); // 8 is added to its initial state, which is 42

    assert(i == 50); //output 50 is expected

    vector<int> input = {1, 2, 3, 4, 5}; //suppose there is an input array
    vector<int> output(input.size()); // and there is an output array of same size as input

    /*
    std::transform will go through input and fill output by adding 1 to each element, using functor add_x(1)
    */
    std::transform(input.begin(), input.end(), output.begin(), add_x(1));

    //printing output
    for(auto x : output){
        cout << x << " ";
    }

    cout << endl;

}