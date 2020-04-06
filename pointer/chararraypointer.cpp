#include <bits/stdc++.h>

using namespace std;

void foo(char **ptr){
    char *ptr1;
    ptr1 = (ptr += sizeof(int))[-1];
    cout << ptr1 << endl;
}

int main(){
    char *arr[] = {"rat", "cat", "dog", "jackal", "lion", "tiger", "zebra"};
    foo(arr);
    return 0;
}