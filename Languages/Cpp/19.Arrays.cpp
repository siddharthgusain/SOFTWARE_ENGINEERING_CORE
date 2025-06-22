#include <iostream>

int main()
{
    int a[10] = {0};                    // 10 variables of type integer
    std::cout << a << std::endl;        // base address
    std::cout << &a << std::endl;       // base address
    std::cout << &a[0] << std::endl;    // first element address /base address
    std::cout << *a << std::endl;       // Value at Base address
    std::cout << *(a + 1) << std::endl; // Value at Base address + 1* (sizeof int) -> a[1]
    for (int value : a)                 // foreach loop -> just a syntactical sugar
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    int *ptr = a;
    ptr[0] = 1;         // *(ptr + 0)
    for (int value : a) // foreach loop -> just a syntactical sugar
    {
        std::cout << value << " ";
    }
    return 0;
}

/*
-> In assembly , only base address of "a" is used, and as the memory is contigous , next
array member can be accessed with basic mathematic :-
base + sizeof(int)* element_number
-> In assembly , theres nothing known as array
-> Every member is access with simple mathematic operation
*/