#include <bits/stdc++.h>

using namespace std;

int main(){
    typedef struct {
        /*max size of each variable is 8 bits*/
        unsigned long a:8;
        unsigned long b:8;
        unsigned long c:8;
        unsigned long d:8;
    } bitfields;

    union data{
        unsigned long i;
        bitfields bf;
    };

    union data x;
    unsigned long v = 0xaabbccdd; /*decimal equivalent is 10101010101110111100110011011101*/

    x.i = v;
    /*little endian system will print 0xaabbccdd from right most end to left most end*/

    /*  8 bit    8 bit    8 bit    8 bit */
    /*   ^        ^        ^        ^    */
    /*___|____ ___|____ ___|____ ___|____*/
    /*10101010 10111011 11001100 11011101*/
    /*   ^        ^        ^        ^    */
    /*   |        |        |        |    */
    /*  0xAA     0xBB     0xCC     0xDD  */
    printf("obtaining every 2 bits from: 0x%x: %x, %x, %x, %x\n", x.i, x.bf.a, x.bf.b, x.bf.c, x.bf.d);


    return 0;
}