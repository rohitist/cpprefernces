#include <bits/stdc++.h>

using namespace std;

char to_lower(char in){
    if(in >= 'A' && in <= 'Z'){
        return (in - ('Z' - 'z'));
    }
    return in;
}

int main(){
    string str = "Rohit";
    
    cout << "Original String: " << str << endl;
    transform(str.begin(), str.end(), str.begin(), to_lower);

    cout << "Lowered String: " << str << endl;

    return 0;
}