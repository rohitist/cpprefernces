#include <bits/stdc++.h>

using namespace std;

class Base{
    virtual void foo(){}
};

union union_class : public Base{ //build error: union class cannot derive from a class

};

int main(){
    Base *base = new union_class();
    return 0;
}