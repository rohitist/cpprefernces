#include <bits/stdc++.h>

using namespace std;

int main() {
    /*sorting in desc order using standard library*/
    map<int, string, greater<int>> mp; //Using std::greater
    mp.insert(make_pair<int, string>(1, "rohit"));
    mp.insert(make_pair<int, string>(2, "rinki"));

    cout << "Sorted map using std::greater<int>\n";
    for(auto& val : mp )
        cout << val.first << endl;

    /*using user comparator*/
    struct comparator{
        bool operator() (int lhs, int rhs) const{ //comparator must be always const
            return (lhs > rhs);
        }
    };
    map<int, string, comparator> mp2;
    mp2.insert(make_pair<int, string>(1, "rohit"));
    mp2.insert(make_pair<int, string>(2, "rinki"));

    cout << "Sorted using comparator\n";
    for(auto& val : mp2 )
        cout << val.first << endl;
    return 0;
}
