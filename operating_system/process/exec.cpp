#include <bits/stdc++.h>

using namespace std;

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
    test_execl();

    /*notice that this is not called after completion of test_execl() because execl replaces current process with
    * new process created by execl
    */
    foo(); //foo() doesn't get called. solution is to fork out a new process and call execl from it
    cout << "done calling execl\n"; 

    return 0;
}