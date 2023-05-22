#include <thread>
#include <future>
#include <iostream>
#include <bits/stdc++.h>

using namespace std::literals; //need to import this for std::this_thread::sleep_for
/*
Use case: a basic example of future and promise introduced in c++11

future is for consumer
promise is for producer


*/

int main(){
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future(); //future is obtained from the promise

    auto t = std::thread([promise = std::move(promise)] () mutable { //mutable is necessary for promise::set_value to compile
        std::this_thread::sleep_for(2000ms); //This is included in c++14

        promise.set_value("Hello Rohit"); //set the value and this will unblock the consumer (future)
    });

    //future.get() will block until the value is available to it via promise::set_value
    std::cout << future.get() << std::endl;

    t.join();

    return 0;
}