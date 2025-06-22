#include <iostream>

namespace test
{
    void print()
    {
        std::cout << "hello";
    }
}

namespace test1
{ 
    void print()
    {
        std::cout << "world";
    }
}

int main()
{
    test::print();
    test1::print();
    return 0;
}

/*
namespace is a identifier which binds multiple identifiers together
and scopes them to avoid  name collision
*/