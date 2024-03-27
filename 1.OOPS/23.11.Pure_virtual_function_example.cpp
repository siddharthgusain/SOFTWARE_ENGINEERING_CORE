#include <iostream>

class Abstract // this can be considered as interface
{
public:
    virtual void display() = 0; // pure virtual function(although syntax is little weird to understand)
};

class Derived : public Abstract
{
public:
    void display()
    {
        std::cout << "derived display implementation";
    }
};

int main()
{
    Derived d;
    d.display();
    return 0;
}