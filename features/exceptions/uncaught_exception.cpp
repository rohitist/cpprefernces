#include <bits/stdc++.h>

using namespace std;

class Oops : std::exception{
    const char* what() const noexcept{
        cout << "Oops\n";
    }
};

class Class{
public:
    Oops e;

    Class(){
        cout << "Class()\n";
    }

    void foo(){
        cout << "foo()\n";
        throw e;
    }

    ~Class(){
        cout << "~Class()\n";
    }
};

int main(){
    Class cls;
    cls.foo(); // not handling exception thrown by foo()

    return 0;
}