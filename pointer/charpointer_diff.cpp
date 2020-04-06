#include <bits/stdc++.h>

int main(){
    char a = 5, b = 30;
    char *p = &a, *q = &b;

    printf("%ld", p - q); //Difference between any two variables of same data type are always one.
    return 0;
}