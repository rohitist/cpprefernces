#include <bits/stdc++.h>

using namespace std;

//Predict the output

class Class{
public:
    Class(){
        cout << "~Class()\n";
    }

    ~Class(){
        cout << "~Class()\n";
        throw 42;
    }
};

int main(){
    try{
        Class cls;
        throw 32; //though this will throw same type of exception as ~Class(). This will lead to exception thrown by ~Class() to be uncaught
    }
    catch(int x){
        cout << "Caught: " << x << endl;
    }

    return 0;
}