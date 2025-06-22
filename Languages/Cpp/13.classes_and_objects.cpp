#include <iostream>

class Player
{
    int x, y;

public:
    Player(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
    void move()
    {
        this->x += 1;
        this->y += 1;
    }
    void print()
    {
        std::cout << this->x << " " << this->y << std::endl;
    }
};

int main()
{
    Player player1(10, 20); // 4 + 4 bytes allocated for player1 variable
    Player player2(20, 30); // 4 + 4 bytes allocated for player2 variable
    player1.move();         // these are more of a normal function call , just that a pointer to current object is passed to it
    player2.move();
    player1.print();
    player2.print();
    return 0;
}

// Functions inside class known as methods , these are just jargons.

/*
-> classes and objects are ways to implement object oriented software design into language
-> classes are nothing just a template which describes the variables and functions that can access these
variables , so that compiler can generate appropriate low level code and can give error in "COMPILE TIME"
if we try to access private members by functions outside the class identifier.
-> In a nutshell classes are small programs in its own containing data + instruction/ functions
-> classes are just syntactical sugar to make our life easier as developer. THAT'S IT
-> In assembly , there is no notion of class, Class variables and methods are converted to normal variables and
functions and "CURRENT Object ADDRESS" is passed to each method while calling
*/