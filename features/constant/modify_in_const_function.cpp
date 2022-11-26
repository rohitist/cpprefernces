#include <bits/stdc++.h>

using namespace std;

class Class{
    mutable int x = 0;// marking it mutable allows to modify this in the context of const function
public:
    void chargeVar(int y) const{ // const function usually doesn't allow to modify anything in it. 
        x = y;
    }
};

int main(){
    Class cls;
    cls.chargeVar(5);

    return 0;
}