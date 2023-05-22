#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

using namespace std;

/*
Use case: Using C++11 Thread class to create threads and lock using unique_lock or lock_guard

unique_lock and lock_guard, both uses RAII pattern (Resource acquisition is initialization)
lock_guard: it has just only feature. it is locked as soon as it is initialized

unique_lock: it can be unlocked explicitly before the end of the scope.
             it can be initialized and locked later when it is required
             multiple unique_lock objects can be locked
*/

class Worker{
private:
    string str;
    std::mutex mutex_t, mutex_t_2, mutex_t_3;
public:
    Worker() : str(""){

    }

    void produce(string str){
        cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << endl;
        this->str = str;
    }

    void consume(){
        {//scope to lock/ unlock mutex using lock_guard
            std::lock_guard<std::mutex> lock(mutex_t); 
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " is locked using lock_guard" << endl;
            cout << "Reading var: " << str << endl;
            //lock.unlock(); //unlock() can't be called on lock_guard
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " locked using lock_guard is getting auto-unlocked at the end of the scope" << endl;
        }

        {//scope to lock/ unlock mutex
            std::unique_lock<std::mutex> lock(mutex_t); 
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " is locked using unique_lock" << endl;
            cout << "Reading var: " << str << endl;
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << "  is being unlocked explicitly using unlock() function" <<  endl;
            lock.unlock(); //unlock() can be called on unique_lock while it cannot be done on lock_guard
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " is already unlocked using unique_lock before the end of the scope" << endl;
        }

        {//scope to lock/ unlock mutex in deferred manner
            std::unique_lock<std::mutex> lock_2(mutex_t_2, std::defer_lock); 
            std::unique_lock<std::mutex> lock_3(mutex_t_3, std::defer_lock); 
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " will be deferred locked using unique_lock" << endl;
            std::lock(lock_2, lock_3); //Two mutextes are locked at once with unique_lock and this avoids the deadlock condition
            cout << "Reading var: " << str << endl;
            cout << __PRETTY_FUNCTION__ << " -Thread id: " << std::this_thread::get_id() << " locked using unique_lock is being unlocked automatically just like lock_guard" << endl;
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