#include <iostream>

int main()
{
    int *ptr;   // just a variable which stored a value of int* type , i.e address of a variable of int type
    int a = 10; // a is variable containing value 10
    ptr = &a;   // store memory address of variable "a" into ptr;
    int **ptr1;
    ptr1 = &ptr;
    std::cout << ptr << std::endl;
    std::cout << &a << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << a << std::endl;
    std::cout << &ptr << std::endl;
    std::cout << ptr1 << std::endl;
    std::cout << &ptr1 << std::endl;
    return 0;
}

/*
-> Pointers are nothing a fixed size space in memory which contains address rather than value.
-> Pointers are way of relative addressing.
-> Pointer Size Depend on OS + CPU architecture(32-bit / 64-bit etc)
*/