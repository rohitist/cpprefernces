#include <bits/stdc++.h>

using namespace std;

void print_function(int i){
    cout << i << " ";
}

class print{
public:
    void operator()(const int& n){
        cout << n << " ";
    }
};

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    //iterate
    cout << "Iterating vector using iterator\n";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it << " "; 
    }
    cout << endl;

    cout << "Iterating vector using index/ access operator\n";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Iterating using function pointer handler\n";
    for_each(vec.begin(), vec.end(), print_function);
    cout << endl;

    cout << "Iterating using class\n";
    for_each(vec.begin(), vec.end(), print());
    cout << endl;

    cout << "Iterating using lambda\n";
    auto printer = [](const int& n){ cout << n << " "; };
    for_each(vec.begin(), vec.end(), printer);
    //for_each(vec.begin(), vec.end(), [](const int& n){ cout << n << " "; }) is also same as above;
    cout << endl;

    //capacity
    cout << "Capacity of the vector: " << vec.capacity() << " and size is: " << vec.size() << endl;


    return 0;
}