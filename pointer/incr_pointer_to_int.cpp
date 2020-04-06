#include <bits/stdc++.h>

using namespace std;

int main(){
    int i = 3;
    int *j;
    int **k;

    j = &i;
    k = &j;
    k++;

    printf("%d ", **k); //prints garbage always
    return 0;
}