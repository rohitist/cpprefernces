#include <bits/stdc++.h>

//Recursive technique to convert decimal number to binary number
void printBinary(unsigned int x){
    if(x/2 != 0) {
        printBinary(x/2);
    }
    std::cout << (x%2);
}
int main() {
    int num = 9;
    int bit_pos = 3;

    std::cout << "Decimal: " << num << std::endl;
    std::cout << "Binary: ";
    printBinary(num);
    std::cout << std::endl;
}