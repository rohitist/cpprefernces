#include <bits/stdc++.h>

using namespace std;

/* struct with no padding, the layout may look like this
|   1   |   2   |   3   |   4   |  

| AA(1) | pad.................. |
| BB(1) | BB(2) | BB(3) | BB(4) | 
| CC(1) | pad.................. |
*/
typedef struct{
    char AA;
    int BB;
    char CC;
} struct_nopack;

/*struct with pack(1), the layout may look like this
|   1   |

| AA(1) |
| BB(1) |
| BB(2) |
| BB(3) |
| BB(4) |
| CC(1) |
*/
#pragma pack(1)
typedef struct{
    char AA;
    int BB;
    char CC;
} struct_packed1;

/*truct with pack(2), the layout may look like this
|   1   |   2   | 

| AA(1) | CC(1) |
| BB(1) | BB(2) |
| BB(3) | BB(4) |
*/
#pragma pack(2)
typedef struct{
    char AA;
    int BB;
    char CC;
} struct_packed2;

int main(){
    //outputs size of int * 3 = 4 * 3 = 12 bytes
    cout << "struct size without packing: " << sizeof(struct_nopack) << endl;
    cout << "struct size using pack(1): " << sizeof(struct_packed1) << endl;
    cout << "struct size using pack(2): " << sizeof(struct_packed2) << endl;

    return 0;
}