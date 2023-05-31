#include <bits/stdc++.h>
#include <memory>
/*
Use case: How to prevent a method getting overriden in derived class
*/

class Base{ 
public:
    virtual void foo() final {} //C++11: Use of final prevents a method getting overriden in derived class
};

class Derived : public Base{ 
public:
    void foo(){

    }
};

int main(){
    std::unique_ptr<Derived> derived = std::make_unique<Derived>(); // Build error: foo() is final in Base

    return 0;
}