#include <bits/stdc++.h>

/*
Use case: A real world example where one could use Factory Method design pattern. 
"Factory design pattern" is not correct way to call it as it is ambiguous and some people use factory pattern as an alias to factory method design pattern

See more: https://en.wikipedia.org/wiki/Factory_method_pattern
*/
using namespace std;

enum class ConnectionType{
    MySQLConnectionType = 0,
    RedisConnection,
    RabbitMQConnection
};

class BasicConnection{
private:
    string user;
    string password;
public:
    virtual void setUser(string usr){
        user = usr;
    }
    virtual void setPassword(string pwd){
        password = pwd;
    }
    virtual void connect() = 0;
};

class MySQLConnection : public BasicConnection{
public:
    void connect(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class RedisConnection : public BasicConnection{
public:
    void connect(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class RabbitMQConnection : public BasicConnection{
public:
    void connect(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

//This is a factory method class
class Creator{
public:
    unique_ptr<BasicConnection> create(ConnectionType conType, string user, string pwd){
        unique_ptr<BasicConnection> basicConnection = nullptr;

        //Factory design pattern is meant to create object based on the type identification
        switch(conType){
            case ConnectionType::MySQLConnectionType:
                basicConnection = make_unique<MySQLConnection>();
                basicConnection->setUser(user);
                basicConnection->setPassword(pwd);
            break;

            case ConnectionType::RabbitMQConnection:
                basicConnection = make_unique<RabbitMQConnection>();
                basicConnection->setUser(user);
                basicConnection->setPassword(pwd);
            break;

            case ConnectionType::RedisConnection:
                basicConnection = make_unique<RedisConnection>();
                basicConnection->setUser(user);
                basicConnection->setPassword(pwd);
            break;
        }

        return basicConnection;
    }
};

int main(){
    string username = "rohit";
    string password = "kumar";

    unique_ptr<Creator> creator = make_unique<Creator>();
    unique_ptr<BasicConnection> basicConnection  = creator->create(ConnectionType::RedisConnection, username, password);
    basicConnection->connect();

    return 0;
}