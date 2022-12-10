#include <bits/stdc++.h>

using namespace std;

bool set_contains(multiset<string>& stringset, string word){
    for(string s : stringset){
        if(s.compare(word) == 0)
            return true;
    }
    return false;
}

string replace_word(forward_list<string>& list, string& sentence){
    //create a set from list. The idea is that it will be faster to search a word from it
    multiset<string> word_set; //multiset because we want it ordered as strings are inserted and have duplicate strings as well
    for(auto lst : list){
        word_set.insert(lst);
    }

    string output = "";
    regex regex_key("\\s+");//try to match by any number of spaces
    regex_token_iterator<string::iterator> tokens(sentence.begin(), sentence.end(), regex_key, -1);
    regex_token_iterator<string::iterator> regex_end;

    for(;tokens != regex_end; tokens++){
        string prefix = "";
        string word(*tokens);

        for(int i = 1; i <= word.length(); i++){//trie (prefix tree) concept to perform matching
            prefix = word.substr(0, i);
            
            if(set_contains(word_set, prefix)){ // if cat is found in cattle then its evaluated as true
                break;
            }
        }
        if(output.length() > 0)
            output.append(" ");
        output.append(prefix);
    }
    return output;
}

int main(){
    forward_list<string> list{"cat", "bat", "rat"};
    string sentence{"the cattle was rattled by the battery"};

    //expected output: the cat was rat by the bat

    cout << replace_word(list, sentence) << endl;

    return 0;
}
