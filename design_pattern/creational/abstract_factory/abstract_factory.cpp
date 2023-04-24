#include <bits/stdc++.h>

using namespace std;

/*
Use case: Demonstrating Abstract Factory Design Pattern
*/
enum class PlatformType{
    LINUX,
    WINDOWS
};

class Button{
public:
    virtual void paint() = 0;
};

class LinuxButton : public Button{
public:
    void paint(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class WindowsButton : public Button{
public:
    void paint(){
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class GUIFactory{
public:
    virtual unique_ptr<Button> createButton() = 0;
};

class LinuxGUI : public GUIFactory{
public:
    unique_ptr<Button> createButton(){
        return make_unique<LinuxButton>();
    }
};

class WindowsGUI : public GUIFactory{
public:
    unique_ptr<Button> createButton(){
        return make_unique<WindowsButton>();
    }
};

//Creator is a client side class. Here the client is creating an object of Button without knowing the implementation of Button and how it will be instantiatied
//GUIFactory is an Abstract factory class that hides the instantiation of Button from the client code
//FOr more see: https://en.wikipedia.org/wiki/Abstract_factory_pattern#References
class Creator{
public:
    void create(PlatformType pt){
        unique_ptr<Button> button = nullptr;

        switch(pt){
            case PlatformType::LINUX:
                button = make_unique<WindowsGUI>()->createButton();
                break;

            case PlatformType::WINDOWS:
                button = make_unique<WindowsGUI>()->createButton();
                break;
        }
        
        button->paint();
    }
};

int main(){
    make_unique<Creator>()->create(PlatformType::WINDOWS);
    
    return 0;
}

