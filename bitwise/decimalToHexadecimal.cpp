#include <bits/stdc++.h>

/*
Use case: Convert a given decimal into hexadecimal represtation
*/
using namespace std;

int main(){
    int decimal =  2545;
    string ans = "";

    int tmp_decimal = decimal;

    while(tmp_decimal != 0){
        int rem = 0;

        char ch;

        rem = tmp_decimal % 16;

        /*You could use switch case to get the quivalent char, if you don't remember offset in the ASCII table*/
        if(rem < 10){
            /*
            integer + 48 = equivalent char in ASCII table
            0 + 48 = '0'
            1 + 48 = '1'
            ........
            ........
            9 + 48 = '9'
            */
            ch = rem + 48;
        }
        else{
            /*
            'A' is positioned at 97 in the ASCII table
            'a' is positioned at 65 in the ASCII table. Use rem + 55 to get char in lower representation. 
            ----------------------------------------
            integer + 87 = equivalent char in ASCII table
            10 + 87 = 'a'
            11 + 87 = 'b'
            ........
            ........
            15 + 87 = 'f'
            */
            ch = rem + 87;
        }

        ans += ch;
        tmp_decimal = tmp_decimal / 16;
    }

    /*Now reverse the string to obtain the correct hex representation*/
    int i = 0, j = (ans.size() - 1);
    while(i <= j){
        swap(ans[i], ans[j]);
        i++, j--;
    }

    cout << "Decimal: " << decimal << " equivalent in hex is: 0x" << ans << endl;

    return 0;
}