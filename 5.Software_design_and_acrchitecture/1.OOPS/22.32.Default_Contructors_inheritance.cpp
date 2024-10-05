#include <iostream>

class Parent
{
    int a;

public:
    Parent() // this is called first
    {
        std::cout << "Parent" << std::endl;
    }
    Parent(int data)
    {
        std::cout << data;
    }
};

class Child : public Parent
{
public:
    Child() // this is called second
    {
        std::cout << "Child" << std::endl;
    }
};

int main()
{
    Child pl;
    return 0;
}