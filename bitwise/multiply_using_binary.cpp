#include <bits/stdc++.h>

/*
Use case: multiply two integers without maths operator

The value of a*b is same as (a*2)*(b/2) if b is even, otherwise the value is same as ((a*2)*(b/2) + a)

*/
using namespace std;

int getProduct(int x, int y){
    int result = 0;

    while(y > 0){
        if(y & 1)
            result += x;

        x <<= 1; //double x
        y >>= 1; //half y
    }

    return result;
}

int main(){
    cout << getProduct(5, 6) << endl;

    return 0;
}