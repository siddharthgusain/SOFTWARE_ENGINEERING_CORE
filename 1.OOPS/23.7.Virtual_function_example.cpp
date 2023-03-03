#include <iostream>

class Base
{
public:
    void display()
    {
        std::cout << "base display()" << std::endl;
    }
    virtual void show()
    {
        std::cout << "base show()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void display()
    {
        std::cout << "Derived display()" << std::endl;
    }
    void show()
    {
        std::cout << "Derived show()" << std::endl;
    }
};

int main()
{
    Base b;
    Derived d;
    Base *ptr; // ptr is pointing to memory location of type Base
    ptr = &b;
    ptr->display(); // display() of Base is called
    ptr->show();    // show() of Base is called

    ptr = &d;       // assigning address of type "Derived" to pointer of type "Base"
    ptr->display(); // base display() is called
    ptr->show();    // *derived show() is called* , without virtual keyword base show() would be called

    d.display(); // derived display() is called
    d.show();    // derived show() is called
    return 0;
}