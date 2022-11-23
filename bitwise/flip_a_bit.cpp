#include <bits/stdc++.h>

void printBinary(unsigned int x){
    if(x/2 != 0) {
        printBinary(x/2);
    }
    std::cout << (x%2);
}
int main() {
    int num = 9;//number to flip
    int bit_pos = 3;//position of the bit to flip

    std::cout << "Binary representation before flipping bit a position " << bit_pos << " : ";
    printBinary(num);
    std::cout << std::endl;

    num = num ^ (1 << (bit_pos - 1)); //left shift 1 by 3 bits and toggle it

    std::cout << "Binary representation after flipping bit at position " << bit_pos << " : ";
    printBinary(num);
    std::cout << std::endl;
}