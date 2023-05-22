#include <bits/stdc++.h>

using namespace std;

/*
Use case: Using C++11 Thread class to create threads and see what happens if the join() is not called
Run: ./cpp11_thread
*/

class Worker{
private:
    string str;
    std::mutex mutex_t;
public:
    Worker() : str(""){

    }

    void produce(string str){
        cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << endl;
        this->str = str;
    }

    void consume(){
        {//scope to auto unlock mutex
            std::unique_lock<std::mutex> lock(mutex_t);
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << endl;
            cout << "Reading var: " << str << endl;
        }
    }
};

int main(){
    Worker *worker = new Worker();

    std::thread producer(&Worker::produce, worker, "Rohit");

    //producer.join(); //join() is necessary otherwise std::terminate will be called and program will be aborted

    return 0;
}