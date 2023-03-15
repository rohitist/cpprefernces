#include <bits/stdc++.h>

using namespace std;

class Singleton{
public:
    //This is thread safe in C++11 but not safe before C++11
    static Singleton& getInstance(){
        static Singleton singleton;
        return singleton;
    }
private:
    //Making below functions private to make them inaccessible
    Singleton() {} //private means don't implement
    ~Singleton() {}

public:
    //Making copy constructor and assignment operator deleted as well as public to result in better error messages
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
};

int main(){
    Singleton& singleton = Singleton::getInstance();

    return 0;
}