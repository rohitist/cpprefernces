#include <pthread.h>
#include <iostream>
#include <algorithm>


/*NOTE: This is an example of multiple producers and one consumer*/

void *consumer(void *), *producer(void *);
pthread_t tid1, tid2;

#define MAXNITEMS 1000000
#define MAXNTHREADS   100

/* globals shared by threads */
int nitems;
int buff[MAXNITEMS];

struct {
    pthread_mutex_t mutex;
    int nput; /* next index to store */
    int nval; /* next value to store */
} put = {
    PTHREAD_MUTEX_INITIALIZER
};

struct {
    pthread_mutex_t mutex;
    pthread_cond_t   cond;
    int            nready; /* number ready for consumer */
} nready = {
    PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER
};

void *producer(void *arg) {
    for( ; ; ) {
        pthread_mutex_lock(&put.mutex); /*this mutex is for array buff*/

        if(put.nput >= nitems) {
            /* array is full. Producer must not write anymore. */
            pthread_mutex_unlock(&put.mutex);
            return (NULL);
        }

        /* we're here. that means array is not full */
        buff[put.nput] = put.nval;
        put.nput++;
        put.nval++;
        pthread_mutex_unlock(&put.mutex);

        pthread_mutex_lock(&nready.mutex); /*this mutex is for nready.nready because producer and consumer*/
        if(nready.nready == 0) {
            /* wake up the consumer before increasing nready.nready. i.e. when nready.nready is 0 */
            pthread_cond_signal(&nready.cond); 
        }
        nready.nready++;
        pthread_mutex_unlock(&nready.mutex);

        *((int *) arg) += 1;
    }
}

void *consumer(void *arg) {
    int i;

    for(i = 0; i < nitems; i++) {
        pthread_mutex_lock(&nready.mutex); /*mutex lock for nready*/
        while(nready.nready == 0)
            pthread_cond_wait(&nready.cond, &nready.mutex); /*wait consumer because it has nothing to consume*/

        nready.nready--;
        pthread_mutex_unlock(&nready.mutex);

        if(buff[i] != i) /*we already know now that put.mutex is released by producer*/
            printf("consumer: buff[%d] = %d\n", i, buff[i]);
    }

    return (NULL);
}


int main(int argc, char **argv) {
    int i, nthreads, count[MAXNTHREADS];
    pthread_t tid_producer[MAXNTHREADS], tid_consumer;

    if(argc != 3) {
        printf("main: usage: <#items> <#threads>\n");
        printf("main: example: ./condition_variable 1000000 5\n");
        return 1;
    }

    nitems = std::min(atoi(argv[1]), MAXNITEMS);
    nthreads = std::min(atoi(argv[2]), MAXNTHREADS);

    /*create all producers*/
    for(i = 0; i < nthreads; i++) {
        count[i] = 0;
        pthread_create(&tid_producer[i], NULL, producer, &count[i]);
    }

    /*create one consumer*/
    pthread_create(&tid_consumer, NULL, consumer, NULL);
    //this_thread::sleep_for(std::chrono::seconds(1));
    
    /*wait for all producers*/
    for(i = 0; i < nthreads; i++) {
        pthread_join(tid_producer[i], NULL);
        printf("main: count[%d] = %d\n", i, count[i]);
    }
    /*wait for the only consumer*/
    pthread_join(tid_consumer, NULL);

    return 0;
}
