#include <iostream>

class Unary
{
    int a;
    int b;

public:
    Unary(int a, int b);
    Unary operator-(); // member function of class , so it can access private members
    void get_data();
};

Unary::Unary(int a, int b)
{
    this->a = a;
    this->b = b;
}

Unary Unary::operator-()
{
    std::cout << "operator function is called" << std::endl;
    this->a = -a;
    this->b = -b;
    return *this;
}

void Unary::get_data()
{
    std::cout << this->a << " " << this->b << std::endl;
}

int main()
{
    int a = 10;
    a = -a; // "-" operator is defined for inbuilt data types
    Unary objl(10, 20);
    -objl; // what does "-" denote in case of user defined datatype?
    objl.get_data();
    Unary obj2 = -objl; // operator function called
    obj2.get_data();
    return 0;
}

/*
OUTPUT:-
operator function is called
-10 -20
operator function is called
10 20
*/