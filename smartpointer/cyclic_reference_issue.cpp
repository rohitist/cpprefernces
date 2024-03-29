//See https://stackoverflow.com/questions/27085782/how-to-break-shared-ptr-cyclic-reference-using-weak-ptr

#include <bits/stdc++.h>

using namespace std;
/*
Use case: Issue of cyclic reference using shared pointer
*/
class B;

class A{
public:
    shared_ptr<B> b;

    A(){
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~A(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class B{
public:
    shared_ptr<A> a;

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
    b_obj->a = a_obj; //Predict the output: Do you think that the dtors will be called?

    return 0;
}