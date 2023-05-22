#include <thread>
#include <future>
#include <iostream>
#include <bits/stdc++.h>

using namespace std::literals; //need to import this for std::this_thread::sleep_for
/*
Use case: a basic example of future and promise introduced in c++11 with exception propagation

future is for consumer
promise is for producer


*/

int main(){
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future(); //future is obtained from the promise

    auto t = std::thread([promise = std::move(promise)] () mutable { //mutable is necessary for promise::set_value to compile
        try{
            std::this_thread::sleep_for(2000ms); //This is included in c++14
            throw std::runtime_error(" Some error happened");
            promise.set_value("Hello Rohit"); //set the value and this will unblock the consumer (future). This is unreachable due to exception
        } catch (...) {
            promise.set_exception(std::current_exception()); //set current exception in promise to notify the consumer (future)
        }
    });

    try{
        //future.get() will block until the value is available to it via promise::set_value
        std::cout << future.get() << std::endl; //This code will not get unblocked because promise triggers exception before set_value
    } catch (const std::exception& e) {
        std::cout << "Propagated exception from promise:" << e.what() << std::endl;
    }

    t.join();

    return 0;
}