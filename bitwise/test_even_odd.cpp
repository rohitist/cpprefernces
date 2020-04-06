#include <bits/stdc++.h>

bool isEven(int x){
    return (x&1 ? false : true);
}
int main(){
    for(int i = 1; i < 12; i++){
        std::cout << i << " - " << (isEven(i) ? "even" : "odd") << std::endl;
    }

    return 0;
}