#include <iostream>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "hello" << std::endl;
    }
    int i = 0;
    while (i < 5)
    {
        std::cout << "hello" << std::endl;
        i++;
    }
    int j = 0;
    do
    {
        std::cout << "hello" << std::endl;
        j++;
    } while (j < 5);
    return 0;
}