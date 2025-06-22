#include <iostream>
#include <memory>

class Smart_pointer
{
    int x;

public:
    Smart_pointer()
    {
        std::cout << "object created" << std::endl;
    }
    ~Smart_pointer()
    {
        std::cout << "object destroyed";
    }
};

int main()
{
    {
        std::unique_ptr<Smart_pointer> ptr = std::make_unique<Smart_pointer>();
    }
    return 0;
}

/*
smart pointers are used to automate heap allocation and deallocation
without us writing delete keyword specifically to deallocate memory
*/