#include <bits/stdc++.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

/*
Use case: POSIX shared memory consumer
*/

const char *shared_file = "shm_test";

void consumer(){
    char data[256] = {0};
    int fd = shm_open(shared_file, O_RDONLY, S_IRUSR | S_IWUSR);
    if(fd == -1){
        perror("open");
        return;
    }

    void *addr = mmap(NULL, 256, PROT_READ, MAP_SHARED, fd, 0);

    memcpy(data, addr, 256);

    cout << "Read from shared memory: " << data << endl;

}

int main(){
    consumer();
    return 0;
}