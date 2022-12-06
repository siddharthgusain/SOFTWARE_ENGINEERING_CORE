#include <iostream>

class Parent1
{
public:
    void display()
    {
        std::cout << "Parent1" << std::endl;
    }
};

class Parent2
{
public:
    void display()
    {
        std::cout << "Parent2" << std::endl;
    }
};

class Child : public Parent1, public Parent2
{
public:
    // void display()
    // {
    //     std::cout << "Child"; // this will be given preference
    // }

    // solving ambiguity
    void display()
    {
        Parent1::display();
        Parent2::display();
    }
};

int main()
{
    Child c;
    c.display();
    c.Parent1::display(); // specifying which display to call
    c.Parent2::display();
    return 0;
}
