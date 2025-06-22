#include <iostream>

void function1()
{
    int a = 0;
    a++;
    std::cout << "INSIDE NON_STATIC : " << a << std::endl;
}

void function2()
{
    static int a = 0; // this static variable is present in different Memory segment of process executable and it remains in memory till process ends
    a++;
    std::cout << "INSIDE STATIC:" << a << std::endl;
}

int main()
{
    function1();
    function1();
    function2();
    function2();
    return 0;
}