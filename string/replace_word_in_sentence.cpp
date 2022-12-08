#include <bits/stdc++.h>

using namespace std;
//TODO: incomplete program
int main(){
    string original = "George Michael";
    string existing_word = "Michael";
    string replacing_word = "Butler";
    int begin = -1, end = -1, offset = 0;

    for(int i = 0; i < original.length(); i++){
        //find first matching letter and once found try to do the rest of the match
        for(int j = 0; j < existing_word.length(); j++){
            if(existing_word[i] != original[j]){
                continue;
            }
            else{
                //at least one match
                begin = j;

            }
        }

    }
}
