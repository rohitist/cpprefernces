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
        if(original[i] == existing_word[0]){
            begin = i;
            for(int j = 1; j < existing_word.length(); j++){
                if(existing_word[j] != original[i]){ //single mismatch and give up
                    break;
                }
                else{
                    offset++;
                }
            }

        }

    }
}
