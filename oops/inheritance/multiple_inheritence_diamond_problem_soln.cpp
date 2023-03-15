#include <bits/stdc++.h>

using namespace std;

/*
    Use case: We want to have below kind of class relationship
                Animal
                /   \
               /     \
               |      |
              Mammal Aquatic
               |      |
               |      |
               \      /
                \    /
                 Whale

    Issue: Two instances of Animal will be created if we create an object of Whale
    
             Animal  Animal
               |      |
               |      |
               |      |
              Mammal Aquatic
               |      |
               |      |
               \      /
                \    /
                 Whale
*/

class Animal{
public:
    Animal(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Mammal : public virtual Animal { //solution is to use virtual inheritence
public:
    Mammal(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Aquatic : public virtual Animal { //solution is to use virtual inheritence
public:
    Aquatic(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Whale : public Mammal, public Aquatic {
public:
    Whale(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};



int main(){
    Animal *animal = new Whale(); // This will succeed to build. For more see: multiple_inheritence_diamond_problem.cpp
    //Whale whale;
    return 0;
}