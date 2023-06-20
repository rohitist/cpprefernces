/*
Decide if you need to store array elements in row major order or column major order
C language supports row major order (see http://en.wikipedia.org/wiki/Row-major_order)
 
In embedded systems, this kind of representation helps to save some space and increased access speed.
*/

#include <bits/stdc++.h>

using namespace std;

#define X_DIMENSION 10
#define Y_DIMENSION 20

int main(){
    int array[X_DIMENSION * Y_DIMENSION] = {0};

    size_t i, j;

    for(i = 0; i < X_DIMENSION; i++){
        for(j = 0; j < Y_DIMENSION; j++){
            cout << "x[" << i << "][" << j << "] = " << array[i*Y_DIMENSION + j] << endl; 
        }
    }

    return 0;
}