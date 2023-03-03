#include <iostream>

class A
{
    int salary = 100;

public:
    int get_salary(); // Member function of A
};

class B
{
public:
    friend int A::get_salary(); // get_salary_function of class A is friend of class B
};

int main()
{
    return 0;
}