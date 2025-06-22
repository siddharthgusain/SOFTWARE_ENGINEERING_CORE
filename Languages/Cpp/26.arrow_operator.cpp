#include <iostream>

struct Player
{
    int x;
    int y;
};

int main()
{
    Player p;
    Player *ptr = &p;
    (*ptr).x = 10;
    ptr->y = 20; // both are same
    std::cout << p.x << " " << p.y;
    return 0;
}