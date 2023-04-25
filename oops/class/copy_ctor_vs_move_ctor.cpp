#include <bits/stdc++.h>

/*
Use case: Demonstrating usage of move ctor
*/
using namespace std;


class Base{
public:
    Base() : var(0){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Base(const Base& other){
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Base(Base&& other) : var(std::exchange(other.var, 0)) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Base& operator=(const Base& rhs){
        cout << __PRETTY_FUNCTION__ << endl;
        if(this != &rhs){
            this->var = rhs.var;
        }
        return *this;
    }

    void setInt(int i){
        var = i;
    }
    int getInt(){
        return var;
    }
private:
    int var;
};

Base foo(Base base){
    return base;
}

int main(){
    Base *base = new Base(); //call default ctor
    Base *base2 = new Base(*base); // call copy ctor. notice the way copy ctor is called for pointer
    *base2 = *base; //calls copy assignment operator

    Base b = foo(Base()); //Creating object and calling foo() at same time creates rvalue. Move ctor is called at this time
    vector<Base> vec; 
    vec.push_back(Base()); //Creating object and calling foo() at same time creates rvalue. Move ctor is called at this time

    Base b2;
    b2.setInt(5);

    Base b3 = std::move(b2); //This also calls user-defined move ctor

    cout << "after move b2 has:" << std::quoted(std::to_string(b2.getInt())) << endl;
    cout << "after move b3 has:" << std::quoted(std::to_string(b3.getInt())) << endl;

    return 0;
}   