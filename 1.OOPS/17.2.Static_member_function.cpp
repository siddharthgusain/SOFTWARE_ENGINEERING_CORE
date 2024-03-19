#include <iostream>

class StaticExample
{
    static int count;

public:
    StaticExample()
    {
        count++;
    }

    static int getCount()
    {
        return count; // can only access static members
    }
};

int StaticExample::count = 10;

int main()
{
    StaticExample s;
    std::cout << StaticExample::getCount(); // calling static function
    return 0;
}