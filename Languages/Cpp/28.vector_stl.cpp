#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec; // this class creates array in heap using "new" keyword
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    for (auto value : vec)
    {
        std::cout << value << " ";
    }
    return 0;
}

/*
-> vector is slow because to increase size it does three steps:-
1. Create new array with bigger size
2. Copy old array to new array
3. Delete old array
*/