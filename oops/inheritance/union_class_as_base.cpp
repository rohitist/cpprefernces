#include <bits/stdc++.h>

using namespace std;



union union_class{ //build error: union class cannot be a base of another class
};

class Base : public union_class{
    
};

int main(){
    
    return 0;
}