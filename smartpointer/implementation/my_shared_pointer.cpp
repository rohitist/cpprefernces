#include <iostream>

/*
 * Implementation of shared_ptr. Not a full proof solution. Ref: https://medium.com/analytics-vidhya/c-shared-ptr-and-how-to-write-your-own-d0d385c118ad
 */
using namespace std;

template <class T>
class my_shared_ptr{
private:
    /*ref_count is pointer instead of unit because we'd like to share this pointer with other shared pointer object and
     *gave it destroyed with other object is destroyed
    */
    uint *ref_count; 
    T *object;

    void __cleanup__(){
        if(ref_count){
            (*ref_count)--;
            if(*ref_count == 0){
                delete object;
                delete ref_count;
            }
        }
    }

public:
    //default constructor
    my_shared_ptr(): object(nullptr), ref_count(new uint(0)){}

    //constructor
    my_shared_ptr(T *ptr) : object(ptr), ref_count(new uint(1)){ //count starts from 1

    } 

    //copy constructor
    my_shared_ptr(const my_shared_ptr& sp){
        if(&sp != nullptr){
            this->object = sp.object;
            this->ref_count = sp.ref_count;

            (*this->ref_count)++;
        }
    }

    //copy assignment operator
    my_shared_ptr& operator=(const my_shared_ptr& sp){
        if(&sp != nullptr){
            __cleanup__(); //clean up underlying object

            this->object = sp.object;
            this->ref_count = sp.object;

            (*this->ref_count)++;
        }
    }

    //move constructor
    my_shared_ptr(const my_shared_ptr&& sp){
        if(*sp != nullptr){
            this->object = sp.object;
            this->ref_count = sp.ref_count;

            sp.object = sp.ref_count = nullptr; //steal the object. that means, setting nullptr to the source will not let it clean up in its dtor
        }
    }

    //move assignment operator
    my_shared_ptr&& operator=(const my_shared_ptr&& sp){
        if(*sp != nullptr){
            __cleanup__();

            this->object = sp.object;
            this->ref_count = sp.ref_count;

            sp.object = sp.ref_count = nullptr; //steal the object. that means, setting nullptr to the source will not let it clean up in its dtor
        }
    }

    //overloading -> operator
    T* operator->() const {
        return this->object;
    }

    //operoading dereference operator
    T& operator*() const {
        return *(this->object);
    }

    //getter method to get the underlying object
    T* get() const {
        return this->object;
    }

    //get reference count
    uint get_count() const {
        return *(this->ref_count);
    }

    //destructor
    ~my_shared_ptr(){
        __cleanup__();
    }
};

class Box{
private:
    int length, width, height;
public:
    Box(): length(0), width(0), height(0){}
};

int main(){
    my_shared_ptr<Box> obj;
    cout << "obj.get_count(): " << obj.get_count() << endl;

    my_shared_ptr<Box> box1(new Box());
    cout << "box1.get_count(): " << box1.get_count() << endl;

    my_shared_ptr<Box> box2(box1);
    cout << "box1.get_count(): " << box1.get_count() << endl;
    cout << "box2.get_count(): " << box2.get_count() << endl;

    return 0;
}