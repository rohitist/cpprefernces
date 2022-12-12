#include <bits/stdc++.h>

using namespace std;

//TODO: not working
void print_in_binary(uint16_t byte){
    if(byte/2 != 0){
        print_in_binary(byte/2);
    }

    cout << (byte%2);
}



int main(){
    uint16_t byte = 0xBABA;

    print_in_binary(byte);
    cout << endl;

    for(int i = 0; i < 16; i++){
        //TODO: perform bitwise swap of bits
    }
    
    print_in_binary(reversed);
    cout << endl;

    return 0;
}