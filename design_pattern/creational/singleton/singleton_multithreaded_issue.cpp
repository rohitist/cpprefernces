#include <bits/stdc++.h>
#include <thread>

using namespace std;

/*
Use case: Singleton design pattern issue while running multiple threads.
Run this program multiple times and you might see two objects created and shown in the console output

See singleton_double_checked_lock.cpp for solution
*/

class Singleton{
public:
    static Singleton *pInstance;
    static Singleton* getInstance(){
        static int count = 0;
        if(pInstance == 0){ //suppose threadA is preempted at line 9 and threadB comes in goes to line 10 and creates the object. threadA wakes up, goes to line B and creates two objects. this is a multithreaded issue
            pInstance = new Singleton();
            cout << "got instance#" << count++ << endl;
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