#include <bits/stdc++.h>

using namespace std;

void parent(){
    cout << "called from parent process with pid: " << getpid() << endl;
}

void child(){
    cout << "called from child process created with pid: " << getpid() << endl;
    sleep(5);//sleep is merely used to demonstrate that parent function will not execute while child is running
}

int main(){
    int n =10;
    pid_t pid = vfork(); //vfork() suspends the parent process until the child is complete

    if(0 == pid){
        child();
    }
    else if(-1 == pid){ //fork() returns -1 upon failure
        cout << "failed to fork()\n";
    }
    else if(0 < pid){ //fork() is > 0 in parent
        parent();
        //wait(NULL);
        cout << "Child is finished\n";
    }
    /*notice the value of n printing garbage. The reason is that vfork doesn't allow modification.
    * Modification is undefined because parent and child share the same stack/address space.
    */
    printf("value of n: %d from pid %d\n", n, getpid()); 

    return 0;
}