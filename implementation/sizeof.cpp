#include <bits/stdc++.h>

#define _sizeof(x) ((char *)(&x + 1) - (char *)&x) 

int main(){
    int x;
    std::cout << _sizeof(x) << std::endl;

    int *y;
    std::cout << _sizeof(y) << std::endl;

    struct node{
        int a;
        char b;
    } node_struct;

    std::cout << _sizeof(node_struct) << std::endl;

    return 0;
}