#include <pthread.h>
#include <iostream>
#include <algorithm>

/*
Use case: A Program to demonstrate deadlock
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
    pthread_mutex_init(&lock_t, NULL);

    pthread_create(&tid, NULL, consumer, NULL);
    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock_t);

    return 0;
}