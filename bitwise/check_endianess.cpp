#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
    On a Little Endian Machine the Byte will be laid out as 0000 0000 0000 0000 0000 0000 0000 0001
    On a Big Endian Machine the Byte will be laid out as 1000 0000 0000 0000 0000 0000 0000 0000
    */
    int a = 1; 
    /*
    stripping 1 byte (char) from 4 byte(integer)
    0000 0000 0000 0000 0000 0000 0000 0001 becomes 0000 0001
    */
    char c = (char)a; 
    if(c == 0x1){
        cout << "Bit order is Little Endian\n";
    }
    else{
        cout << "Bit order is Big Endian\n";
    }

    return 0;
}