#include <bits/stdc++.h>

using namespace std;

int main(){
    char *string1;
    char string2[] = "my name is rohit";

    string1 = string2;
    string1 += 6;

    cout << string1 << endl;
    
    return 0;
}