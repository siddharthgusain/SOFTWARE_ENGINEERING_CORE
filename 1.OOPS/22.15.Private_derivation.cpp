#include <iostream>

class Parent
{
private:
    int private_member_parent;

public:
    int public_member_parent;
};

class Child : private Parent
{
private:
    int private_member_child;

public:
    int public_member_child;
};

int main()
{
    Child obj;
    obj.public_member_child = 10; // only this variable is "directly" accessible
    // obj.public_member_parent;
    // not accessible as public members of Parent goes to private section of Child
    return 0;
}