#include <iostream>

class Ambiguity
{
    int a;

public:
    Ambiguity()
    {
        this->a = 0;
    }
    Ambiguity(int data = 10)
    {
        this->a = a;
    }
};

int main()
{
    Ambiguity obj; // here which constructor should be called (ambiguity)?
    return 0;
}