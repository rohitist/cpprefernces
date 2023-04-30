#include <bits/stdc++.h>

using namespace std;

void test_endian_2(){
    union{
        uint32_t i;
        char c[4];
    }bint = {0x01020304};

    if(bint.c[0] == 0x01){
        cout << "This is a big endian architecture" << endl;
    }
    else(bint.c[3] == 0x01){
        /**
         * On a little endian arch, bint.i = 0x01020304 will be distributed in bint.c as bint.c[0] = 0x04 (LSB byte), bint.c[1] = 0x03
         * bint.c[2] = 0x02 and bint.c[3] = 0x01
        */
        cout << "This is a little endian architecture" << endl;
    }
}

int main(){
    /*
    On a Little Endian Machine the Byte will be laid out as 0000 0000 0000 0000 0000 0000 0000 0001
    On a Big Endian Machine the Byte will be laid out as 1000 0000 0000 0000 0000 0000 0000 0000
    */

    /*
    stripping 1 byte (char) from 4 byte(integer)
    0000 0000 0000 0000 0000 0000 0000 0001 becomes 0000 0001
    */
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

    //also
    test_endian_2();

    return 0;
}