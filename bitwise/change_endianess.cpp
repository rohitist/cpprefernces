#include <bits/stdc++.h>

using namespace std;

/*
* Built-in way to convert little endian byte order to big endian
* Each byte is swapped in this conversion but bits. Don't get confused with reversing bits.
* In 0x12345678, 0x12 is swapped with 0x78 and 0x34 is swapped with 0x56, therefore the output is 0x78563412
*
*/

uint32_t to_big_endian(uint32_t var){
    uint32_t ret = ( ((var & 0x000000FF) << 24) | \
                     ((var & 0x0000FF00) << 8 ) | \
                     ((var & 0x00FF0000) >> 8 ) | \
                     ((var & 0xFF000000) >> 24 ) );

    return ret;
}

int main(){
    uint32_t little_endian = 0x12345678;
    printf("In Little Endian Order: 0x%x\n", little_endian);

    uint32_t big_endian =  __builtin_bswap32(little_endian);
    printf("In Big Endian Order (using __builtin_bswap32()): 0x%x\n", big_endian);
    printf("In Big Endian Order (using own implementation ): 0x%x\n", to_big_endian(little_endian));


    return 0;
}