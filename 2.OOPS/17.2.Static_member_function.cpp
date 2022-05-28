#include <iostream>

class Static
{
    static int count;

public:
    Static()
    {
        count++;
    }

    static int getCount()
    {
        return count; // can only access static members
    }
};

int Static::count = 10;

int main()
{
    Static s;
    std::cout << Static::getCount(); // calling static function
    return 0;
}