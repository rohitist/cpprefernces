#include <bits/stdc++.h>

using namespace std;

/* This program is a follow up solution to exec.cpp
*/

void test_execl(){
    const char *binaryPath = "/usr/bin/ls"; //full path to the new binary is required by execl
    const char *arg1 = "ls"; //name of the process. It has no effect on to how a process is run
    const char *arg2 = "-lh"; //1st arg to the process
    const char *arg3 = "/home"; //2nd arg to the process

    int ret = execl(binaryPath, arg1, arg2, arg3, NULL);
    if(ret < 0)
        cout << "couldn't complete execl\n";

}

void foo(){
    cout << __PRETTY_FUNCTION__ << endl;
}

int main(){
    pid_t pid = fork();
    if(0 == pid){
        //calling execl from the child process
        test_execl();
    }

    foo(); 
    cout << "done calling execl\n"; 

    return 0;
}