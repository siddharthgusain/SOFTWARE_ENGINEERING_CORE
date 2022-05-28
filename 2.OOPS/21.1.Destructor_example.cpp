#include <iostream>

class Destructor_example
{
public:
    Destructor_example()
    {
        std::cout << this << " constructor called" << std::endl;
    }

    ~Destructor_example()
    {
        std::cout << this << " Destructor called" << std::endl;
    }
};

int main()
{
    Destructor_example obj1;
    {
        Destructor_example obj2; // object scope is inside the block only
    }
    /* here destructor of obj2 is called , when compiler compiles and makes the object code
        of this source code it adds the instruction which calls constructor and destructor
        As, a programmer we dont need to explicitly call these functions
    */
    return 0;
}

/*
OUTPUT:-
0x7fff549846f0 constructor called
0x7fff549846f4 constructor called
0x7fff549846f4 Destructor called
0x7fff549846f0 Destructor called
*/