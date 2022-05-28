#include <iostream>

template <class T> // generic function
T add(T a, T b)
{
    return a + b;
}

int main()
{
    int a = 5;
    std::cout << add(a, a);
    return 0;
}