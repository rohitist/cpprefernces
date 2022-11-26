#include <bits/stdc++.h>

int main(){
    int *ptr = 2; // compilation error: pointer can only be initialized with 0
    printf("%lu\n", sizeof(ptr));
    return 0;
}