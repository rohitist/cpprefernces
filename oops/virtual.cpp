#include<bits/stdc++.h>
/*
 *The program demonstrates size of classes due to several factors
 *
 */

using namespace std;
class A{
};

class B{
public:
	void foo() {};
};

class C{
public:
	int i;
};

class D{
public:
	virtual void foo(){}
};

class E{
public:
	/*4 bytes for int + 4 bytes for alignment + 8 bytes for virtual function pointer*/
	int i;
	virtual void foo() {}
};

class F{
public:
	virtual void foo() {}
	virtual void bar() {}
};

class D_child : public D{
public:
	void foo(){}
};

class E_child : public E{
public:
	void foo(){}
};

int main(){
	cout << "size of class A: " << sizeof(A) << endl;
	cout << "size of class B: " << sizeof(B) << endl;
	cout << "size of class C: " << sizeof(C) << endl;
	cout << "size of class D: " << sizeof(D) << endl;
	cout << "size of class E: " << sizeof(E) << endl;
	cout << "size of class F: " << sizeof(F) << endl;
	cout << "size of class D_child: " << sizeof(D_child) << endl;
	cout << "size of class E_child: " << sizeof(E_child) << endl;
	return 0;
}
