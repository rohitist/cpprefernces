#include <bits/stdc++.h>

using namespace std;

//Use case: Why should we use friend

class Paragraph{
private:
    friend ostream& operator<<(ostream& os, const Paragraph& para); //declaring friend function within private doesn't make it private
    string sentence;
public:
    Paragraph(const string& str) : sentence(str){}
};

ostream& operator<<(ostream& os, const Paragraph& para){
    return os << para.sentence;
}

int main(){
    Paragraph para("My name is Rohit");
    cout << para << endl;

    return 0;
}

//See: https://en.cppreference.com/w/cpp/language/friend