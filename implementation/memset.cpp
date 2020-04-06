#include <bits/stdc++.h>

void * _memset(void *ptr, int ch, int sz){
    unsigned char *p = (unsigned char *)ptr;
    while(sz > 0){
        *p = ch;
        p++;
        sz--;
    }
    return p;
}

int main(){
    char str[20];

    _memset(str, '1', 20);
    std::cout << str << std::endl;

    _memset(str, '2', 20);
    std::cout << str << std::endl;

    _memset(str, '\0', 20);
    std::cout << str << std::endl;

    return 0;
}