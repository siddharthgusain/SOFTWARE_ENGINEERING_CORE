#include <iostream>

class Player
{
private:
    int x, y;

public:
    int getter() const // getter function is constant that means it will not modify class data members(that's it)
    {
        return this->x;
    }
};

int main()
{
    const int a = 10;     // constant
    const int *ptr = &a;  // ptr value can change but it is pointing to constant value
    int const *ptr1 = &a; // ptr1 value can't be changed and but value it is pointing can be changed
    return 0;
}