#include <bits/stdc++.h>

using namespace std;

//Custom class to create exception class
class Oops : std::exception {
    const char* what() const noexcept{
        return "Oops\n";
    }
};

class Class{
public:
    Oops e;

    Class(){}

    ~Class(){
        cout << "~Class()\n";
        throw e;
    }
};

int main(){
    Class cls;

    return 0;
}