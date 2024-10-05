#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "default constructor of parent called" << std::endl;
    };
    Parent(int data)
    {
        std::cout << "Parameterized constructor of parent called==>" << data << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "default constructor of Child called" << std::endl;
    };
    Child(int data) : Parent(data) // this syntax is quite new , it is calling base class constructor
    {
        std::cout << "Parameterized constructor of child called==>" << data << std::endl;
    }
};

int main()
{
    Child c1;     // default constructor called (Parent -> child)
    Child c2(10); // parameterized constructor called (Parent-> child)
    return 0;
}

/* NOTE:- there is no "super" keyword in c++ like in java , so somehow we need to call base class
constructor for that c++ has different syntax
-> super keyword is not there in C++ to avoid deadly diamond problem that arises as ambiguity in multiple inheritance
-> In Java there is no support for multiple inheritance, so super keyword can be used
*/