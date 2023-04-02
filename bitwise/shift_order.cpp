#include <iostream>

//Use case: if two shifts are occurring in a line then the resolution takes from left to right

int main() {
    int i[3] = {2, 3, 4};
    std::cout << "Output: " << (i[0] << i[1] << i[2]) << std::endl; //shift operations are ordered from left to right
    /*
    Step 1: i[0] << i[1] = 2 << 3 = 16
    Step 2: 16 << i[2] = 16 << 4 = 256
    */

    return 0;
}