#include <bits/stdc++.h>

using namespace std;

int main(){
    char *ptr = "hello";
    char a[22];

    *ptr = "world"; //compilation error: ptr is a char pointer which behaves as a const

    printf("%s %s", ptr, a);
    return 0;
}