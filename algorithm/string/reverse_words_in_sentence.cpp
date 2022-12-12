#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(string sentence){
    vector<string> tokens;
    regex pattern("\\s+");
    regex_token_iterator<string::iterator> it(sentence.begin(), sentence.end(), pattern, -1);
    regex_token_iterator<string::iterator> end;

    for(; it != end; it++){
        tokens.push_back(*it);
    }

    return tokens;
}

string reverse_sentence(string sentence){
    string output = "";
    //tokenize the sentence and store in an multiset
    vector<string> tokens = tokenize(sentence);

    //traverse the vector in reverse and store in a string and return it
    for(auto it = tokens.rbegin(); it != tokens.rend(); it++){
        if(output.length() > 0) output.append(" ");
        output.append(*it);
    }

    return output;
}

int main(){

    string sentence = "my name is rohit kumar";
    cout << reverse_sentence(sentence) << endl;

    return 0;
}