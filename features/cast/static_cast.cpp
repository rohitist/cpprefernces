#include <bits/stdc++.h>

using namespace std;

int main(){
    int i = 5.8; //also note that whether it is 5.51 or 5.8, casting into float results to floor value, which is 5
    float f = static_cast<float>(i);

    cout << "static_cast from int to float: " << f << endl;

    return 0;
}