#include <iostream>

class B;
/* forward declaration for class B as c++ compiler compiles Top down , if it sees any undefined
identifier , it will throw error
*/
class A
{
    int number;

public:
    void set_number(int num);
    friend void max(A obj1, B obj2); // declaring friend function
};

class B
{
    int number;

public:
    void set_number(int num);
    friend void max(A obj1, B obj2); //// declaring friend function
};

void A::set_number(int num)
{
    this->number = num;
}

void B::set_number(int num)
{
    this->number = num;
}

void max(A obj1, B obj2) // definition friend function
{
    if (obj1.number > obj2.number)
    {
        std::cout << obj1.number;
        return;
    }
    std::cout << obj2.number;
    /*
        Note :- we are "directly" accessing "number" which is private variable but as max is friend function
        this private variable is accessible inside it directly
    */
}

int main()
{
    A obj1;
    B obj2;
    obj1.set_number(10);
    obj2.set_number(20);
    max(obj1, obj2);
    return 0;
}