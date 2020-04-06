#include <bits/stdc++.h>

void printBinary(unsigned int x){
    if(x/2 != 0) {
        printBinary(x/2);
    }
    std::cout << (x%2);
}
int main() {
    int num = 9;
    int bit_pos = 1;

    printBinary(num);
    std::cout << std::endl;

    num = num & ~(1 << (bit_pos - 1));

    printBinary(num);
    std::cout << std::endl;
}