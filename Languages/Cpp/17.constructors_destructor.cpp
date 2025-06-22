#include <iostream>

class Student
{
    int marks;

public:
    Student()
    {
        this->marks = 30;
    }

    ~Student()
    {
        this->marks = 0;
        std::cout << this->marks;
    }

    void print();
};

void Student::print()
{
    std::cout << this->marks << std::endl;
}

int main()
{
    Student s1;
    // this is where constructor call is added automatically by compiler
    // We dont have to call the constructor in our source code , but it will be present in assembly code
    s1.print();
    return 0;
}

/*
-> Constructors are functions only , nothing special , just that
we dont need to call them by writing function call , this heavy lifting is done by
compiler on our behalf

-> Even if we dont write constructor , a empty default constructor is added by compiler
which does nothing.
-> Same Goes for destructor
*/