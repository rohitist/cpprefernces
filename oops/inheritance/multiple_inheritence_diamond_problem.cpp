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

class Mammal : public Animal {
public:
    Mammal(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Aquatic : public Animal {
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
    //Animal *animal = new Whale(); // This will fail to build with error "Parent is an ambiguous base of GrandSon" if Son and Daughter doesn't inherits with virtual keyword
    Whale whale;
    return 0;
}