#include <bits/stdc++.h>

/*
Predict the output
*/
using namespace std;

class A{
public:
    A(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void foo(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~A(){ //non virtual dtor
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class B : public A{
public:
    B(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~B(){ //non virtual dtor
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class C : public B{
public:
    C(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~C(){ //non virtual dtor
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    A *a = new C();
    a->foo();

    delete a;

    return 0;
}