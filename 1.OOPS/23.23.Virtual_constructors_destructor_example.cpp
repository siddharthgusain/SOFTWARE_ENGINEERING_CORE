#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Contructor" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived() // constructor can't be virtual
    {
        std::cout << "Derived Constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main()
{
    // 1. Derived d; works fine no need of virtual destructor in base class
    Base *ptr = new Derived(); // Derived size space is allocated in "heap" , ptr is present in stack frame of main function
    delete ptr;                // delete p means deallocate the memory space in heap, this requires Base destructor to be virtual
    return 0;
}