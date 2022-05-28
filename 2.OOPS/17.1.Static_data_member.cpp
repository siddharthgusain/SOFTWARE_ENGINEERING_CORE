#include <iostream>

class counter
{
    static int count;

public:
    counter()
    {
        count++;
    }

    int getCount()
    {
        return this->count;
    }
};

int counter::count;

int main()
{
    counter c1;
    std::cout << "c1==>" << c1.getCount() << std::endl;
    counter c2;
    std::cout << "c1==>" << c1.getCount() << std::endl;
    std::cout << "c2==>" << c2.getCount() << std::endl;
    return 0;
}