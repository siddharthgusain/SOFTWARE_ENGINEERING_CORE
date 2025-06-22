#include <iostream>

void increment(int &ref)
{
    ref++;
}

int main()
{
    int some_very_big_variable_name = 10;
    int &ref = some_very_big_variable_name; // ref is alias for "a", can be used for large variable name
    increment(some_very_big_variable_name);
    std::cout << ref;
    return 0;
}