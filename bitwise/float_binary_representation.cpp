#include <bits/stdc++.h>

using namespace std;

void float_to_binary(float f){
    union{
        float f;
        uint32_t u;
    }fu = { .f = f};

    int i = sizeof(f) * CHAR_BIT; // CHAR_BIT = number of bits in a char byte. Usually it is 8 bits but in some systems (say DSP) it is 10 bits per byte

    printf ("  ");
    while(i--)
        printf("%d ", (fu.u >> i) & 0x1);

    putchar('\n');
    printf (" |- - - - - - - - - - - - - - - - - - - - - - "
            "- - - - - - - - - -|\n");
    printf (" |s|      exp      |                  mantissa"
            "                   |\n\n");
}

int main(){
    float fl = 3.14159f;

    printf("IEEE-754 Single-Precision representation of: %f\n\n", fl);
    float_to_binary(fl);
    return 0;
}