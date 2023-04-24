#include <bits/stdc++.h>

using namespace std;

/*
Use case: Demonstrating the usage of protoype design pattern

Advantage: When creating an object is costly, it is advised to use cloning an existing object. Cloning in C++ is achieved by using copy constructor

How is cloning better than instantiating with new operator:
-----------------------------------------------------------
        Imagine a scenario when an object is created with new operator and in its corresponding constructor, some heavy lifting is done such as few SQL operations
        performed and results were saved for caching. 
        Now, imagine you want to create another object of the same class but you would like to avoid few SQL operations. In that case, it is efficient to call copy constructor
        of the previosuly created and copy over all cached data to the newly created object. This is called prototype design pattern
*/

class Connection{
public:
    void setUsername(string user){
        _username = user;
    }
    void setPassword(string pwd){
        _password = pwd;
    }
    void setIP(string ip){
        _ip = ip;
    }

    virtual unique_ptr<Connection> clone() = 0;
private:
    string _username;
    string _password;
    string _ip;
};

class OracleConnection : public Connection{
public:
    OracleConnection(){
        //Perform some heavy lifting such as initiating cache that is done by performing some SQL operations or reading a file, etc
        cout << __PRETTY_FUNCTION__ << endl;
    }

    OracleConnection(const OracleConnection& sqlConnection) {
        //Copy cache that were initiated in the default constructor
        cout << __PRETTY_FUNCTION__ << endl;
    }

    unique_ptr<Connection> clone() override {
        cout << __PRETTY_FUNCTION__ << endl;
        return make_unique<OracleConnection>(*this); //calling copy constructor
    }
};

class RedisConnection : public Connection{
public:
    RedisConnection(){
        //Perform some heavy lifting such as initiating cache that is done by performing some SQL operations or reading a file, etc
        cout << __PRETTY_FUNCTION__ << endl;
    }

    RedisConnection(const RedisConnection& redisConnection) {
        //Copy cache that were initiated in the default constructor
        cout << __PRETTY_FUNCTION__ << endl;
    }

    unique_ptr<Connection> clone() override {
        cout << __PRETTY_FUNCTION__ << endl;
        return make_unique<RedisConnection>(*this); //calling copy constructor
    }
};

enum class ConnectionType{
        ORACLE,
        REDIS
};

//Client factory class
class ConnectionFactory{
private:

    map<int, unique_ptr<Connection>> object_record;

public:
    ConnectionFactory(){
        //new objects are created only once. For similar we will clone() function to create object in the createConnection function
        cout << __PRETTY_FUNCTION__ << endl;
        object_record[static_cast<int>(ConnectionType::ORACLE)] = make_unique<OracleConnection>();
        object_record[static_cast<int>(ConnectionType::REDIS)] = make_unique<RedisConnection>();
    }

    unique_ptr<Connection> createConnection(ConnectionType conType){
        cout << __PRETTY_FUNCTION__ << endl;
        return object_record[static_cast<int>(conType)]->clone();
    }
};

int main(){
    unique_ptr<ConnectionFactory> factory = make_unique<ConnectionFactory>(); //init ConnectionFactory

    //client wants to create another instance of Redis connection
    unique_ptr<Connection> redisConnection = factory->createConnection(ConnectionType::REDIS);

    return 0;
}

