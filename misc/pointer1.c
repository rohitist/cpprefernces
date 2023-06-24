#include <stdio.h>

/*Predict the output*/

int main(){
    char arr[15] = "pointer array";
    int *ptr;
    ptr = arr;
    printf("%c",ptr[1]);
    return 0;
}