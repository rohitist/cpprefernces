#include <bits/stdc++.h>

using namespace std;

#define NUM_OF_BITS_IN_UINT16 15

void rotate_right(uint16_t* byte, int n){
    *byte = (*byte >> n) | (1 << NUM_OF_BITS_IN_UINT16);
}
int main(){
    uint16_t byte = 0xAB01;

    rotate_right(&byte, 1);
    printf("0x%x\n", byte);
    return 0;
}