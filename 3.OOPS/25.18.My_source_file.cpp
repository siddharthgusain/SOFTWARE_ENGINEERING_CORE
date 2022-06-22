#include "25.17.test.h";
#include <iostream>

My_header::My_header(int a, int b)
{
    this->a = a;
    this->b = b;
}

int My_header::add()
{
    return this->a + this->b;
}

int main()
{
    My_header obj(10, 20);
    std::cout << obj.add();
}