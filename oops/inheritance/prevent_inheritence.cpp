#include <bits/stdc++.h>
#include <memory>
/*
Use case: How to prevent inheriting a class using final keyword
*/

class Base final{ //C++11: Use of final prevents a class altogether from being inherited

};

class Derived : public Base{ //Build error: cannot derive from final Base class

};

class Parent{
private:
    Parent(){} //private Parent ctor
};
class Child : public Parent{

};

int main(){
    std::unique_ptr<Derived> derived = std::make_unique<Derived>();

    std::unique_ptr<Child> child = std::make_unique<Child>(); //Build error as Parent ctor is private

    return 0;
}