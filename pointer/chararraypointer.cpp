#include <bits/stdc++.h>

using namespace std;

/*
Predict the output
*/

void foo(char **ptr){
    char *ptr1;
    ptr1 = (ptr += sizeof(int))[-1]; //size of int is 4 bytes. so ptr will increase to 4th index.
    cout << ptr1 << endl;
}

int main(){
    char *arr[] = {"rat", "cat", "dog", "jackal", "lion", "tiger", "zebra"};
    foo(arr);
    return 0;
}