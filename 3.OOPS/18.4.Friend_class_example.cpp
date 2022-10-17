#include <iostream>

class A
{
    int private_variable;

public:
    A()
    {
        this->private_variable = 0;
    }
    friend class B; // B is friend of A so B can access private variable of class A
};

class B
{
public:
    void display(A obj)
    {
        std::cout << obj.private_variable; // accesing private variable of class A object
    }
};

int main()
{
    A A_class_obj;
    B B_class_obj;

    B_class_obj.display(A_class_obj);
    return 0;
}