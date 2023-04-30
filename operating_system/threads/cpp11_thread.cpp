#include <bits/stdc++.h>

using namespace std;

/*
Use case: Using C++11 Thread class to create threads
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
    std::thread consumer1(&Worker::consume, worker);
    std::thread consumer2(&Worker::consume, worker);

    producer.join();
    consumer1.join();
    consumer2.join();

    return 0;
}