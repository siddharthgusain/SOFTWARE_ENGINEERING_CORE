#include <iostream>
#include <vector>

void test()
{
    std::cout << "hello" << std::endl;
}

void print_value(int value)
{
    std::cout << value << std::endl;
}

void for_each(const std::vector<int> &values, void (*callback)(int))
{
    for (int value : values)
        callback(value);
}

int main()
{
    auto a = &test; // address of function to "a"
    a();
    void (*ptr)() = &test;
    (*ptr)();
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for_each(vec, print_value); // more like passing callback
    return 0;
}

/*
-> function name is actually a address in machine code which corresponds to
address of function inside code segment of a process , so functions have address
, thats why function pointer is just a variable pointing to function address

-> function pointer are more useful for asynchronous programming , as they are a form of
"CALLBACKS" that we use frequently in "GUI programming".
*/