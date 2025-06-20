#include <bits/stdc++.h>

using namespace std;

/*
Usage: CRTP (Curiously Recurring Template Pattern) is a C++ idiom that allows static polymorphism.
It is popular in embedded systems and performance-critical applications.
*/

/*Logger is a Base class and should be ideally in header file*/
template <typename Derived>
class Logger {
public:
    void log(const string& message) {
        static_cast<Derived*>(this)->write(message);
    }
};  

/*UARTLogger doesn't declare a template and could be placed in cpp file*/
class UARTLogger : public Logger<UARTLogger> {
public:
    void write(const string& message) {
        cout << "ConsoleLogger: " << message << endl;
    }
};

/*FileLogger doesn't declare a template and could be placed in cpp file*/
class FileLogger : public Logger<FileLogger> {
public:
    void write(const string& message) {
        cout << "FileLogger: " << message << endl;
    }
};  

int main() {
    UARTLogger uartLogger;
    uartLogger.log("This is a UART log message.");

    FileLogger fileLogger;
    fileLogger.log("This is a File log message.");

    return 0;
}