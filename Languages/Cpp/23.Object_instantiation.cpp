#include <iostream>

class Player
{
private:
    int x;

public:
    Player() : x(0) {} // default constructor

    Player(const int &x) : x(x) {} // parameterized constructor

    const int &get_x() const
    {
        return this->x;
    }
};

int main()
{
    Player p;                     // static memory allocation(stack)
    Player *ptr = new Player(40); // Dynamic allocation(heap allocation) --> uses operating system sys calls to get memory using some algos like First fit , best fit etc
    std::cout << p.get_x() << std::endl;
    Player p1 = Player(20); // parameterized constructor called
    std::cout << p1.get_x() << std::endl;
    std::cout << ptr->get_x() << std::endl;
    std::cout << sizeof(*ptr) << std::endl;
    delete ptr;
    return 0;
}