#include <bits/stdc++.h>

void *_memcpy(void *target, void *source, size_t size){
    if((uintptr_t)target % sizeof(long) == 0 &&
        (uintptr_t)source % sizeof(long) == 0 &&
        size % sizeof(long) == 0){
            /*len%sizeof(long) checks if you are trying to copy full-longs not a part of long
             *checks for alignment and if true, copies fast(sizeof(long) bytes at a time)*/

            long *tgt = (long *)target;
            const long *src = (const long *)source;

            for(int i = 0; i < size/sizeof(long); i++){
                tgt[i] = src[i];
            } 
    }
    else {
        /*this is for the mis-aligned arrays (slow copy (1 byte at a time))*/
        char *tgt = (char *)target;
        const char *src = (const char *)source;

        for(int i = 0; i < size/sizeof(long); i++){
            tgt[i] = src[i];
        } 
    }
    return target;
}

int main(){
    struct strct{
        int a;
        char b;
    };

    struct strct fst;
    struct strct scnd;

    fst.a = 2;
    fst.b = 'b';

    _memcpy(&scnd, &fst, sizeof(struct strct));

    std::cout << scnd.a << " - " << scnd.b << std::endl;

    return 0;
}