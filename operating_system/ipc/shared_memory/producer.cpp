#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

/*
Use case: POSIX shared memory producer
*/

using namespace std;

const char *shared_file = "shm_test";
void producer(){

    int fd = shm_open(shared_file, O_CREAT | O_RDWR, (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP));
    if(fd < 0){
        perror("open");
        return;
    }
    //increase the size
    int res = ftruncate(fd, 256);

    //map shared memory
    void *addr = mmap(NULL, 256, PROT_WRITE, MAP_SHARED, fd, 0);

    char data[256] = "Hello World";
    int len = strlen(data) + 1;
    memcpy(addr, data, len);

    cout << "Run the consumer within 10 seconds\n";
    sleep(10);

    cout << "Cleaning up shared memory\n";

    res = munmap(addr, 256);

    fd = shm_unlink(shared_file);

}

int main(){
    producer();
    return 0;
}