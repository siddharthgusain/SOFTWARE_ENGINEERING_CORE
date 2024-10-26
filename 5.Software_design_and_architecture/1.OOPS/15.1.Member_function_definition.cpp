#include <iostream>

class Rectangle
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

float Rectangle::get_length()
{
    return this->length;
}

int main()
{
    Rectangle r1;
    r1.set_length(10);
    std::cout << r1.get_length();
    return 0;
}