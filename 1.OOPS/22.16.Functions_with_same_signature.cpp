#include <iostream>

class Parent
{
    int a;

public:
    void show_name() // function with same name
    {
        std::cout << "Parent member function";
    }
};

class Child : public Parent
{
    int a;

public:
    void show_name() // function with same name
    {
        std::cout << "Child member function";
    }
};

int main()
{
    Child obj;
    obj.show_name(); // here child member function is given priority
    return 0;
}