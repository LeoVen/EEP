#include <iostream>
#include <string>

using namespace std;

class MyFriendClass;
class MyClass;

class MyClass
{
    friend void friend_method(MyClass *myClass);
protected:
    long protected_number;
    MyFriendClass *friend_class;

private:
    void protected_method()
    {
        cout << "My class says: " << protected_number << " is my protected number" << endl;
    }

public:
    MyClass(long message)
    {
        protected_number = message;
    }
    void my_friend_protected_method();
};

class MyFriendClass
{
    friend class MyClass;
protected:
    void protected_method()
    {
        cout << "Friend class protected method" << endl;
    }
};

void friend_method(MyClass *myClass)
{
    cout << "Friend method says: " << myClass->protected_number << " is my protected number" << endl;
}

void MyClass::my_friend_protected_method()
{
    friend_class->protected_method();
}

int main(int argc, char const *argv[])
{
    MyClass my_class(2011154783);
    
    friend_method(&my_class);

    my_class.my_friend_protected_method();

    return 0;
}
