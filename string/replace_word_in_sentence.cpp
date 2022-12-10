#include <bits/stdc++.h>

using namespace std;
//TODO: incomplete program

multiset<string> string_to_set(string sentence){
    multiset<string> tokens; //multiset because we want it ordered as strings are inserted and have duplicate strings as well

    regex pattern("\\s+");
    regex_token_iterator<string::iterator> out(sentence.begin(), sentence.end(), pattern, -1);
    regex_token_iterator<string::iterator> end;

    for(; out != end; out++){
        tokens.insert(string(*out));
    }

    return tokens;
}

string replace_word(string original, string existing_word, string replacing_word){
    string output = "";
    multiset<string> words = string_to_set(original);

    for(string word : words){
        if(word.compare(existing_word) == 0){  
            if(output.length() > 0) output.append(" "); 
            output.append(replacing_word);
        }
        else{
            if(output.length() > 0) output.append(" ");
            output.append(word);
        }
    }

    return output;
}
int main(){
    string original = "George Michael is my name";
    string existing_word = "Michael";
    string replacing_word = "Butler";

    cout << replace_word(original, existing_word, replacing_word) << endl;

    return 0;
}
