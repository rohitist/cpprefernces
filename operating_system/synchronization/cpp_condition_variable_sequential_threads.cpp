#include <bits/stdc++.h>

using namespace std;

/*
Use case: Spawn two threads, one thread would print odd number and other thread would print even number
and the output will be printed in natural number order
*/

/*
Condition variable allows to avoid busy-waiting (for some condition to be fulfilled by another thread)
Busy waiting is achieved in a thread by using some a loop and sleep mechanism. 

Condition variable is stateless and hence it doesn't remember its last state. Therefore, a mutex is required 
in wait() function to move it from locked to state to wait state by atomically unlocking it.
*/
std::condition_variable cond_var; //condition variable will be used for notification
std::mutex mutex_t; //mutex will be used for locking critical section

int number = 1;

void odd_thread(){
    while(true){
        std::unique_lock<std::mutex> ul(mutex_t); //mutex auto-locked from here
        if(number%2 != 0){
            cout << number++ << endl;
            ul.unlock();
            cond_var.notify_one(); //notify other thread only after unlocking mutex
        }
        else{
            //if the number is even, then wait
            /*condition variable requires mutex as an argument to disallow race condition on itself.
            condition variable wait() will later atomically unlock the mutex to allow other thread to work on it.
            */
            cond_var.wait(ul, [](){ return (number%2 != 0); }); 
        }        
    }
}

void even_thread(){
    while(true){
        std::unique_lock<std::mutex> ul(mutex_t); //mutex auto-locked from here
        if(number%2 == 0){
            cout << number++ << endl;
            ul.unlock();
            cond_var.notify_one(); //notify other thread only after unlocking mutex
        }
        else{
            //if the number is odd, then wait till it becomes even
            /*condition variable requires mutex as an argument to disallow race condition on itself.
            condition variable wait() will later atomically unlock the mutex to allow other thread to work on it.
            */
            cond_var.wait(ul, [](){ return (number%2 == 0); });
        }  
    }
}

int main(){
    std::thread t1(odd_thread);
    std::thread t2(even_thread);

    t1.join();
    t2.join();

    return 0;
}