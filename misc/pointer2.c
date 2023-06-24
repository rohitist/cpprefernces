#include <stdio.h>

/*Predict the output*/

int main()
{
    int *iptr;
    int i, arr[2][2] = {10, 11, 12, 13};
    iptr = *arr ;
    printf("%d ", *(iptr+2));
    return 0;
}