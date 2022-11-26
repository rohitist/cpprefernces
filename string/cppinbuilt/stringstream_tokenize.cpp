#include <bits/stdc++.h>

int main(){
    std::string str = "My, Name, Is, Rohit";
    std::stringstream ss(str);
    std::string line;

    while(std::getline(ss, line, ',')){
        std::cout << line << std::endl;
    }

    return 0;
}