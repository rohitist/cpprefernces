#include <bits/stdc++.h>

using namespace std;

class Square{
public:
    Square(int num) : number(num) {}
    ~Square() {}

    //Note that there is no return type explicity mentioned in the conversion operator
    operator long(){
        return getSquare();
    }
private:
    long getSquare(){
        return number*number;
    }
    int number;
};

int main(){
    Square sq(2);
    cout << "Square of 2 is: " << sq << endl;
    return 0;
}