#include <iostream>

class Grandparent
{
protected:
    int a;

public:
    void display()
    {
        std::cout << this->a;
    }
};

class Parent1 : public virtual Grandparent
{
};

class Parent2 : public virtual Grandparent
{
};

class Child : public Parent1, public Parent2
{
};

int main()
{
    Child c;
    c.display();
    return 0;
}

/* Note:- virtual inheritance increases the size of object created by Child ,
this over head is information needed to avoid duplication generally virtual pointers
We will talk about virtual table , virtual pointers in next section
*/