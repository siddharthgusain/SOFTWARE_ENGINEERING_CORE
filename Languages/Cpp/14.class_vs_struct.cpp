#include <iostream>

struct Player_stuct
{
    int x, y;
};

class Player_class
{
    int x, y;
};

int main()
{
    Player_class p;
    Player_stuct p1;
    std::cout << p1.x; // possible
    // std::cout << p.x;  // can't be accessed
    return 0;
}

/*
-> In C , classes and stucture are way different , we can't define method
inside struture
-> In CPP , only difference is class members are private by default while struct are public
*/