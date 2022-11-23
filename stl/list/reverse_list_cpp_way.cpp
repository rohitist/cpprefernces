#include <bits/stdc++.h>

using namespace std;

int main(){
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    //reverse linked list using inbuilt reverse iterator
    for(list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it){
        cout << *it << endl;
    }
    return 0;
}