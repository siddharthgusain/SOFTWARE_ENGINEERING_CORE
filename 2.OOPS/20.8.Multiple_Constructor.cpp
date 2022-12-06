#include <iostream>

class Multiple_Constructor
{
    int a;

public:
    Multiple_Constructor();
    Multiple_Constructor(int data);
    Multiple_Constructor(Multiple_Constructor &obj);
    void set_data(int data);
};

Multiple_Constructor::Multiple_Constructor()
{
    std::cout << "Default called" << std::endl;
    this->a = 0;
}

Multiple_Constructor::Multiple_Constructor(int data)
{
    std::cout << "Parameterized called" << std::endl;
    this->a = data;
}

Multiple_Constructor::Multiple_Constructor(Multiple_Constructor &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->a = obj.a;
}

void Multiple_Constructor::set_data(int data)
{
    this->a = data;
}

int main()
{
    Multiple_Constructor obj1; // Default called
    obj1.set_data(50);
    Multiple_Constructor obj2(100);  // Parameterized called
    Multiple_Constructor obj3(obj1); // Copy constructor called
    return 0;
}