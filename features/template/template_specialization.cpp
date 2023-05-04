#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Adder{

public:
    Adder() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    T add(T a, T b);
};

template <typename T>
T Adder<T>::add(T a, T b){ //This works for number type datatype such as int, float, etc. But we don't want this for char type
    cout << __PRETTY_FUNCTION__ << endl;
    return (a + b);
}

//add function has been template specialized to perform special function for char type
template <>
char Adder<char>::add(char a, char b){
    cout << __PRETTY_FUNCTION__ << endl;
    int x = (a - '0');
    int y = (b - '0');
    return (x + y);
}

int main(){
    Adder<int> intadd;
    int z = intadd.add(5, 6);
    cout << "Calling Adder<int>::add -> " << z << endl;

    Adder<char> charadd;
    char c = charadd.add('e', 'f');
    cout << "Calling Adder<char>::add -> " << c << endl;

    return 0;
}