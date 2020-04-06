#include <bits/stdc++.h>

int main(){
    int x = 1;

    char *y = (char *)&x;

    if(*y+48 == '1') {
        std::cout << "little endian\n";
        /*
         *           higher memory
         *               ----->
         *           +----+----+----+----+
         *           |0x01|0x00|0x00|0x00|
         *           +----+----+----+----+
         *           A
         *           |
         *           &x
         * 
         */
    }
    else if(*y+48 == '1') {
        std::cout << "big endian\n";
        /*
         *           higher memory
         *               ----->
         *           +----+----+----+----+
         *           |0x00|0x00|0x00|0x01|
         *           +----+----+----+----+
         *           A
         *           |
         *           &x
         * 
         */
    }

    return 0;
}