#include <bits/stdc++.h>

using namespace std;

int add_binary(int left, int right){
    int x = 0, y = 0;

    do{
        x = left ^ right; // XOR operation will preserve the addition without carry
        y = left & right; // AND operation will yield carry-out
        left = y << 1; //Keep on adding carry until it becoms zero
        right = x;
    }while(y);

    return x;
}

int add_binary_recursion(int left, int right){
    int carry = (left & right) << 1;
    int result = left ^ right;

    if(carry == 0)
        return result;
    else
        return add_binary_recursion(carry, result);
}

int add_increment_op(int left, int right){
    for(int i = 0; i < right; i++){
        left += 1;
    }

    return left;
}

int main(){
    cout << "Adding two ints without plus operator and using binary: " << add_binary(4, 5) << endl;
    cout << "Adding two ints without plus operator and using binary recursively: " << add_binary_recursion(4, 5) << endl;
    cout << "Adding two ints without plus operator and using increment operator: " << add_increment_op(4, 5) << endl;
    return 0;
}