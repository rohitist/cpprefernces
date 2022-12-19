#include <bits/stdc++.h>

using namespace std;

void print_in_binary(uint16_t byte){
    /*this function doesn't print the leading 0*/
    if(byte/2 != 0){
        print_in_binary(byte/2);
    }

    cout << (byte%2);
}



int main(){
    uint16_t byte = 0x5003;
    uint16_t out = 0x0000; 

    print_in_binary(byte);
    cout << endl;

    for(int i = 0; i < 16; i++, byte >>= 1){
        out = (out << 1) | (byte & 1); //get the bit from lsb and keep pushing it towards msb
    }

    print_in_binary(out);
    cout << endl;

    return 0;
}