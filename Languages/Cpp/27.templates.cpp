#include <iostream>

template <typename T>
struct Player
{
    T x;
    T y;
};

int main()
{
    Player<int> p;
    Player<float> p1;
    p.x = 10;
    p.y = 20;
    return 0;
}

/*
-> templates are just declaration for generics to reduce code redundancy
-> Compiler generates specific class type internally based on template type provided by us in source code
*/