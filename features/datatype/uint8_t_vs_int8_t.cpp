#include <bits/stdc++.h>

//Use case: difference between int8_t and uint8_t. Predict the output
int main(){
    int8_t a = 200; //int8_t ranges from -127 to 127 as it is signed
    uint8_t b = 100; //uint8_t ranges from 255 to 0

    if(a > b){
        std::cout << "greater\n";
    }
    else{
        std::cout << "lesser\n"; //this is the output
    }

    return 0;
}