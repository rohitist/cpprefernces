#include <bits/stdc++.h>

using namespace std;

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
pthread_t tid1, tid2;

void *consumer1(void *), *producer1(void *);

int main(int argc, char **argv) {
    void *status;

    pthread_create(&tid1, NULL, consumer1, NULL);
    pthread_create(&tid2, NULL, producer1, NULL);
    this_thread::sleep_for(std::chrono::seconds(1));
    
    pthread_join(tid1, &status);
    pthread_join(tid2, &status);

    pthread_rwlock_destroy(&rwlock);

    return 0;
}

void *consumer1(void *arg){ //reader thread
    pthread_rwlock_rdlock(&rwlock);
    printf("consumer1 got a read lock\n");
    //this_thread::sleep_for(std::chrono::seconds(1));
    pthread_rwlock_unlock(&rwlock);

    return (NULL);
}

void *producer1(void *arg){ //writer thread
    pthread_rwlock_wrlock(&rwlock);
    printf("producer1 got a write lock\n");
    pthread_rwlock_unlock(&rwlock);

    return (NULL);
}