#include <bits/stdc++.h>

int main(){
    std::string str = "Rohit";
    std::cout << "Original String: " << str << std::endl;

    std::reverse(str.begin(), str.end());
    std::cout << "Reversed String: " << str << std::endl;
    return 0;
}