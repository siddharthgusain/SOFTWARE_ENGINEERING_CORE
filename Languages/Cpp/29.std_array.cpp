#include <iostream>
#include <array> // contains array class

int main()
{
    std::array<int, 5> arr = {0}; // works more like static array in cpp , it creates array in stack not on heap unlike vector
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}