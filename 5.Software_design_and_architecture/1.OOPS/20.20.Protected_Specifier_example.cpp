#include <iostream>

class Parent
{
    int private_member; // will not be inherited

protected:
    int protected_member; // will be inherited

public:
    int public_member; // will be inherited
};

class Child : public Parent
{
public:
    void access_protected_member()
    {
        // this->private_member; not possible as private member is not accessible inside derived class "directly"
        std::cout << this->protected_member; // but this is possible
    }
};

int main()
{
    Child obj;
    return 0;
}