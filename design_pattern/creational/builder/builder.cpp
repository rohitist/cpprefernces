#include <bits/stdc++.h>

using namespace std;

/*
Use case: Use of Builder Design Pattern

Advantage of builder design pattern:
1. When constructor has too many parameters that it becomes difficult to remember which is what
2. Setter functions make room for error if a developer misses any parameter
3. Builder class provides a way to throw an exception if there is less parameters set in the builder
*/

/*Field is an immutable class. That means, its state cannot be changed once the object is created
It means that object will be created once using ctor, copy ctor but later the object cannot be changed because there is no means to change its private fields.
*/
class Field{
    //FieldBuilder is a frined to Field. That means, it will access private members of Field to construct Field object
    friend class FieldBuilder;
public:
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getAddress() const {
        return address;
    }
   
    Field(const Field& other){
        this->name = other.name;
        this->age = other.age;
        this->address = other.address;
    }

    Field() : name("NA"), age(0), address("NA") {}

private:
    Field& operator=(const Field& other);

    string name;
    int age;
    string address;
};

class FieldBuilder{
public:
    FieldBuilder setName(string name){
        _field.name = name;

        return *this; //return object of the builder
    }
    FieldBuilder setAge(int age){
        _field.age = age;

        return *this; //return object of the builder
    }
    FieldBuilder setAddress(string address){
        _field.address = address;

        return *this; //return object of the builder
    }
    FieldBuilder(){}
    
    //builder function
    Field build() const{
        return _field;
    }
private:
    Field _field;

    FieldBuilder& operator=(const FieldBuilder& other);
    FieldBuilder(const Field& other);
};

int main(){
    Field field = FieldBuilder().setName("Rohit").setAge(33).setAddress("Pune").build(); //FieldBuilder setters return object of itself so builder object are able to be chained
    return 0;
}
 



