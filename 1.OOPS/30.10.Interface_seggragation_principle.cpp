#include <iostream>

class Waiter_interface
{
    virtual void serve_customers() = 0;
    virtual void take_order() = 0;
}; // interface for waiter

class Chef_interface
{
    virtual void cook_food() = 0;
    virtual void decide_menu() = 0;
}; // interface for chef

class Waiter : public Waiter_interface
{
public:
    void serve_customers()
    {
        std::cout << "serving..";
    }

    void take_order()
    {
        std::cout << "taking order";
    }
};

int main()
{
    Waiter w1;
    w1.serve_customers();
    w1.take_order();
}

// both chef and waiter have different interfaces which can be modified without affecting each other
