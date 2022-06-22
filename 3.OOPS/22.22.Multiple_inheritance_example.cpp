#include <iostream>

class Parent1
{
protected:
    int parent1_data; // note this is protected member
public:
    void set_parent1_data(int data)
    {
        this->parent1_data = data;
    }
};

class Parent2
{
protected:
    int parent2_data; // note this is protected member
public:
    void set_parent2_data(int data)
    {
        this->parent2_data = data;
    }
};

class Child : public Parent1, public Parent2
{
private:
    int child_data = 10;

public:
    void display()
    {
        std::cout << this->parent1_data << std::endl; // directly accessible as these are "protected" variables
        std::cout << this->parent2_data << std::endl;
        std::cout << this->child_data;
    }
};

int main()
{
    Child c;
    c.set_parent1_data(22);
    c.set_parent2_data(33);
    c.display();

    Parent1 p;
    // p.parent1_data; this is not possible as protected member are inherited but still can't be access "directly" with object
    return 0;
}