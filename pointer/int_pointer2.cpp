#include <bits/stdc++.h>

int main(){
    int *ptr;
    *ptr = 5;

    printf("%d\n", *ptr); //runtime error: coredump because we cannot initialized pointer variable
    return 0;
}