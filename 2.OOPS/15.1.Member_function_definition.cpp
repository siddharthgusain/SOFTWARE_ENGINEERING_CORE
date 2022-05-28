#include <iostream>

class rectangle
{
    float length;
    float breadth;

public:
    float get_length();
    void set_length(float length)
    {
        this->length = length;
    }
};

float rectangle::get_length()
{
    return this->length;
}

int main()
{
    rectangle r1;
    r1.set_length(10);
    std::cout << r1.get_length();
    return 0;
}