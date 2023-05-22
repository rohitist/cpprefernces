#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

using namespace std;

/*
Use case: Using C++11 Thread class to create threads and lock using unique_lock twice on same mutex object
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
        {//scope to lock/ unlock mutex
            std::unique_lock<std::mutex> lock(mutex_t); 
            std::unique_lock<std::mutex> lock_2(mutex_t); //locking same mutex twice here has undefined behaviour. threads may get into dead lock situation
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " is locked using unique_lock" << endl;
            cout << "Reading var: " << str << endl;
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << "  is being unlocked explicitly using unlock() function" <<  endl;
            lock.unlock(); //unlock() can be called on unique_lock while it cannot be done on lock_guard
            lock_2.unlock();
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " is already unlocked using unique_lock before the end of the scope" << endl;
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