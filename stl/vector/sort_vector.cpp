#include <bits/stdc++.h>

using namespace std;

/*
Use case: sort a vector of class using < overloading
*/

class MyClass{
public:
    int data;
    MyClass(int v) : data(v) {}

    bool operator<(const MyClass& rhs) const {
        return (data < rhs.data);
    }
};

int main(){
    vector<MyClass> vec;
    vec.push_back(MyClass(22));
    vec.push_back(MyClass(4));
    vec.push_back(MyClass(67));
    vec.push_back(MyClass(1));
    vec.push_back(MyClass(9));

    //iterate
    cout << "Iterating using auto for loop before sorting\n";
    for(auto i : vec){
        cout << i.data << " ";
    }

    sort(vec.begin(), vec.end());

    cout << "Iterating using auto for loop after sorting\n";
    for(auto i : vec){
        cout << i.data << " ";
    }

    return 0;
}