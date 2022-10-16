#include <iostream>

class counter
{
    static int count;

public:
    counter()
    {
        count++;
    }

    int *get_count()
    {
        return &count;
    }
};

int counter::count; // this is important

int main()
{
    counter c1;
    std::cout << "c1==>" << c1.get_count() << std::endl;
    counter c2;
    std::cout << "c1==>" << c1.get_count() << std::endl;
    std::cout << "c2==>" << c2.get_count() << std::endl;
    return 0;
}

/*
All three address returned by getCount() is same for both objects
*/