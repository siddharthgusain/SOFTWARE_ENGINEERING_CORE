#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "----------FIRST WAY--------------" << std::endl;

    // First Way to iterate vec object
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    std::cout << "--------SECOND WAY----------------" << std::endl;

    // Second Way
    for (int value : vec)
    {
        std::cout << value << std::endl;
    }

    std::cout << "--------THIRD WAY----------------" << std::endl;
    // third way
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    return 0;
}

/*
1. Iterator may not be used with normal data types like Arrays , vector (Continuous Data Structures)
2. They are useful for Data structures like tree , graph , Maps , sets etc(Basically Non-continuous Data Structures)
3. This Concept will be there in every programming language like JS , Java etc
*/