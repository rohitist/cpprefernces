//See https://stackoverflow.com/questions/27085782/how-to-break-shared-ptr-cyclic-reference-using-weak-ptr

#include <bits/stdc++.h>

using namespace std;
/*
Use case: Solution to the issue of cyclic reference using shared pointer
*/

class B;

class A{
public:
    weak_ptr<B> b; //weak_ptr to break the cyclic reference

    A(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~A(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class B{
public:
    weak_ptr<A> a; //weak_ptr to break the cyclic reference

    B(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~B(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main(){
    shared_ptr<A> a_obj = make_shared<A>();
    shared_ptr<B> b_obj = make_shared<B>();

    a_obj->b = b_obj;
    b_obj->a = a_obj;

    return 0;
}