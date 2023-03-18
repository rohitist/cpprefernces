#include <bits/stdc++.h>

/*
Use case: Basic example of how user level threads are created using pthread lib on linux os
*/

using namespace std;

pthread_t tid[2] = {0};
static int thread_counter = 0;
pthread_mutex_t mutex_t;

void *consumer(void *arg){
    pthread_mutex_lock(&mutex_t);
    cout << "Thread #" << thread_counter++ << endl;
    pthread_mutex_unlock(&mutex_t);

    return NULL;
}

int main(){
    pthread_mutex_init(&mutex_t, NULL);

    for(int i = 0; i < 2; i++){
        pthread_create(&tid[i], NULL, consumer, NULL); //2nd arg = configure with pthread_attr_t with stuffs like stack size, scheduling params, etc. 3rd arg = function args
        cout << "Thread created with pid: " << tid[i] << endl;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&mutex_t);

    return 0;
}