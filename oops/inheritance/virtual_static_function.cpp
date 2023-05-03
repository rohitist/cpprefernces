/*
Use case: Is virtual static function allowed?
*/

class Base{
public:
    virtual static void foo(){} //Build error: A function cannot be both static and virtual
};

int main(){

    return 0;
}