#include <bits/stdc++.h>

using namespace std;

int main()
{
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};

    cout << "length of array: " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "length of array: " << *(&arr + 1) - arr << endl;

    return 0;
}
