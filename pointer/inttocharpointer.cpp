#include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 130;
    char *ptr;

    ptr = (char *)&a;

    /*this prints -126 becoz char has a limit of -128 to 127. going beyond this limit will restart the loop through its range*/
    printf("%d", *ptr);

    return 0;
}