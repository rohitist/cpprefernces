#include <bits/stdc++.h>

using namespace std;

/*
Structure packing is useful in scenarios:
    -Writing a structure into EEPROM and padding is not desirable

Structure packing is not desirable on some systems:
    -there's certain performance penalty without padding as unaligned bytes are slower to access
    -it may cause SIGBUS (Segmentation Fault) on some processors in a case when one system is sending packed bytes to another system that requires
     aligned/ unpacked bytes

Choose packing carefully
    -Suppose cost of network I/O is higher than performance
    -Better use for internal processing only when you know what you are doing
    -restore original alignment from stack using "#pragma pack(pop)" when packing is no longer required

Refer: https://stackoverflow.com/questions/7793511/are-there-performance-issues-when-using-pragma-pack1#65005770
*/

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