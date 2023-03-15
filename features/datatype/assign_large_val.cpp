#include <bits/stdc++.h>

using namespace std;

/*
int8_t means signed char and its value ranges from -128 to 127 
therefore, int8_t representation of 127 =  127 (0111 1111) where 0 is the sign bit
therefore, int8_t representation of 128 = -128 (1000 0000)
therefore, int8_t representation of 129 = -127 (1000 0001)
therefore, int8_t representation of 130 = -126 (1000 0010)
*/
int main(){
    for(int i = 127; i <=200; i++){
        int8_t j = static_cast<int8_t>(i);
        printf("assigning large value %d to int8_t: %d \n",i, j);
    }
    return 0;
}