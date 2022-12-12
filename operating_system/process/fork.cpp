#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

/* This program demostrates what happens when execl is called from main process
*/

void parent(){
    cout << "called from parent process with pid: " << getpid() << endl;
}

void child(){
    cout << "called from child process created with pid: " << getpid() << endl;
    sleep(5);
}

int main(){
    pid_t pid = fork(); //fork() returns zero pid in parent process
    if(0 == pid){
        child();
    }
    else if(-1 == pid){ //fork() returns -1 upon failure
        cout << "failed to fork()\n";
    }
    else if(0 < pid){ //fork() is > 0 in parent
        parent();
        wait(NULL);
        cout << "Child is finished\n";
    }

    return 0;
}