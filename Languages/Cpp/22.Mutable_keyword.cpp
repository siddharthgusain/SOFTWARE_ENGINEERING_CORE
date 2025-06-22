#include <iostream>

class Player
{
    int marks;
    mutable int stamina;

public:
    Player() : marks(0), stamina(0) {}
    void set_stamina() const
    {
        this->stamina += 10; // even though set_stamina is const , but it can change mutable data member of class
    }
};

int main()
{
    Player p;
    p.set_stamina();
    return 0;
}