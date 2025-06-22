#include <iostream>
#include <vector>

int main()
{
    int a = 10;
    auto b = a;
    std::cout << b << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    return 0;
}

/*
-> auto is one way to make cpp dynamically typed , although compiler automatically puts actual type
during compilation
*/