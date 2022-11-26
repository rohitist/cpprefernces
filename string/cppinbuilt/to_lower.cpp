#include <bits/stdc++.h>

using namespace std;

int main(){
    string str = "Rohit";

    cout << "Original String: " << str << endl;
    transform(str.begin(), str.end(), str.begin(), [](const char c){ return tolower(c); });

    cout << "Lowered String: " << str << endl;

    return 0;
}