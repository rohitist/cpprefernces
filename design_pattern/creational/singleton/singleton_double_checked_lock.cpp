#include <bits/stdc++.h>
#include <thread>

using namespace std;

/*
Use case: Demonstrating double checked lock to solve multi-threaded issue with SIngleton design pattern
*/

std::mutex mutex_t;

class Singleton{
public:
    static Singleton *pInstance;
    static Singleton* getInstance(){
        static int count = 0;

        //demonstrating double checked lock
        if(pInstance == 0){ //1st test
            const lock_guard<mutex> lock(mutex_t);
            if(pInstance == 0){  //2nd test
                pInstance = new Singleton();
                cout << "got instance#" << count++ << endl;
            }
        }
        return pInstance;
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

Singleton* Singleton::pInstance = 0;

int main(){
    thread thread1(Singleton::getInstance);
    thread thread2(Singleton::getInstance);

    thread1.join();
    thread2.join();

    return 0;
}