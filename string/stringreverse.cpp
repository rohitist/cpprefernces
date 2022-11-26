#include <bits/stdc++.h>

using namespace std;

int main(){
    string str = "Rohit";
    std::cout << "Original String: " << str << std::endl;
    for(int i = 0, j = (str.length() - 1) ; i < j; ++i, j--){
        str[i] ^= str[j];
        str[j] ^= str[i];
        str[i] ^= str[j];
    }
    std::cout << "Reversed String: " << str << std::endl;
    
    return 0;
}