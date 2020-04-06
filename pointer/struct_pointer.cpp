#include<bits/stdc++.h>

using namespace std;

struct node{
    int a, b, c;
};

int main(){
    struct node num = {3,4,5};
    struct node *ptr = &num;

    cout << *((int *)ptr) << endl;
    cout << *((int *)ptr + 1 + (3 - 2)) << endl;
    
    return 0;
}