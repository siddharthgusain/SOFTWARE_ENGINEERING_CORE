#include <iostream>

class Car
{
public:
    void print_details()
    {
        std::cout << "Car class" << std::endl;
    }
};

class Tata
{
    Car c; // Tata "Has-a" Car object

public:
    void display()
    {
        std::cout << "Tata class" << std::endl;
        c.print_details();
    }
};

int main()
{
    Tata obj; // in memorty obj size will be equal to size of car obj
    obj.display();
    return 0;
}