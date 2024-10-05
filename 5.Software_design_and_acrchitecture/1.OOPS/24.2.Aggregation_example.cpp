#include <iostream>

class Car
{
public:
    void print_details()
    {
        std::cout << "Car class" << std::endl;
    }
};

class Truck
{
public:
    void print_details()
    {
        std::cout << "Truck class" << std::endl;
    }
};

class Tata
{
    Car c;   // Tata is a company which "Has-a" Car object
    Truck t; // Tata is a company which "Has-a" Truck object as well
public:
    void display()
    {
        std::cout << "Tata class" << std::endl;
        c.print_details();
    }
};

int main()
{
    Tata obj; // in memory obj size will be equal to size of car obj + Truck Obj
    obj.display();
    return 0;
}