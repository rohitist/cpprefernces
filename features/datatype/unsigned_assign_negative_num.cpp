#include <bits/stdc++.h>

int main(){
    int i = -1;
    unsigned int j = i;

    /*see: https://stackoverflow.com/questions/2711522/what-happens-if-i-assign-a-negative-value-to-an-unsigned-variable
    * assigning negative number to unsigned number yields very large value because a negative number
    * is stored as 2's complement and unsigned number is just stored in plain binary format and after assignment, signed bit (MSB) which
    * is at supposedly 32th position is simply comverted into 2^32 = 4294967295
    */
    std::cout << "Assigning negative number to unsigned type yields: " << j << std::endl;

    return 0;
}