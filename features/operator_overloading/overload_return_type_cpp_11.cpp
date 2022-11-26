#include <bits/stdc++.h>

using namespace std;

/*
This will result error because we cannot overload by return type.

int from_string(const char *str) { return std::stoi(str); }
float from_string(const char *str) { return std::stof(str); }
*/

/*c++11 way to overload by return type: Return type resolver*/

class from_string{
private:
    const string m_str;

public:
    from_string(const char *str) : m_str(str) {}

    //Note that there is no return type explicity mentioned in the conversion operator
    template <typename data_type>
    operator data_type() {
        if(is_same<data_type, int>::value)
            return stoi(m_str);
        else if(is_same<data_type, float>::value)
            return stof(m_str);
    }
};

int main(){
    int n_int = from_string("123");
    float n_float = from_string("123.111");

    cout << "overload return type by int : " << n_int << endl;
    cout << "overload return type by float : " << n_float << endl;

    return 0;
}