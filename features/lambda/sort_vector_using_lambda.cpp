#include <bits/stdc++.h>

using namespace std;

/*
Use case: use of lambda expression to sort vector 
*/

int main(){
    vector<int> vec = {4, 1, 8, 3, 7, 55, 6};

    cout << "before sort\n";
    for(auto v : vec){
        cout << v << " ";
    }

    cout << endl;

    /*
    About lambda syntax:
    
    "[]" :  capture clause. [&] means capture all variables by reference. [] means capture all variables by value. [var] means access var by value
            [=] means capture all variables by value. [&var1, var2] means capture var1 by reference and var2 by value
    "->" : return type
    */
    sort(vec.begin(), vec.end(), [](const int& a, const int& b) -> bool { return a < b;});

    cout << "after sort\n";
    for(auto v : vec){
        cout << v << " ";
    }

    cout << endl;

    return 0;
}