#include <bits/stdc++.h>
/*
Uase case: Showing difference between prefix and postfix increment operator overloading
*/
using namespace std;

class Number{
private:
    int i;
public:
    Number(int x) : i(x) {}

    Number& operator++(){
        ++i;
        return *this;
    }

    Number operator++(int){ //postfix increment has int as format argument
        Number tmp = *this; //Taking backup here and will send the old object 
        ++i;
        return tmp;
    }

    operator int(){ //conversion operator
        return i;
    }

};

int main(){
    Number num(5);

    cout << "Number value during prefix increment operator: " << ++num << endl;
    cout << "Number value during postfix increment operator: " << num++ << endl;
    cout << "Number value after prefix increment operator: " << num << endl;

    return 0;
}