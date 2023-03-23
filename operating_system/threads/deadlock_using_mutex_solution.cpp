#include <pthread.h>
#include <iostream>
#include <algorithm>

/*
Use case: A Program to avoid deadlock even if lock is held more than once by the same thread.
This is a solution to problem demostrated in the program deadlock_using_mutex.cpp
*/
pthread_t tid;
pthread_mutex_t lock_t;

void *consumer(void *arg){
    pthread_mutex_lock(&lock_t);
    //critical section
    pthread_mutex_lock(&lock_t); //twice locking causes deadlock
    std::cout << "returning from consumer\n"; //This will not print
    return NULL;
}

int main(){
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE); // Setting the mutex attribute to allow recursive (re-eterant) mutex

    pthread_mutex_init(&lock_t, &attr);

    pthread_create(&tid, NULL, consumer, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock_t);

    return 0;
}