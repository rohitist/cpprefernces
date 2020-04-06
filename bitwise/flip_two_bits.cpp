#include <bits/stdc++.h>

void printBinary(unsigned int x){
    if(x/2 != 0) {
        printBinary(x/2);
    }
    std::cout << (x%2);
}
int main() {
    int num = 9;
    int bit_pos_a = 2;
    int bit_pos_b = 3;

    printBinary(num);
    std::cout << std::endl;

    int mask = (1 << (bit_pos_a - 1)) | (1 << (bit_pos_b - 1));

    printBinary(mask);
    std::cout << std::endl;

    num = num ^ mask;

    printBinary(num);
    std::cout << std::endl;
}