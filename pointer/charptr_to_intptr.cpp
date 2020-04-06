#include<stdio.h>

/*this will compile with gcc compiler only*/

int main(){
    char arr[15] = "pointer array";
    int *ptr;
    ptr = arr;
    
    printf("%c\n", ptr[1]); /*output: t because ptr[1] increases by 4 bytes*/

    return 0;
}