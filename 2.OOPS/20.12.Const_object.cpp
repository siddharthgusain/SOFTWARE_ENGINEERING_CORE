#include <iostream>

class Account
{
    int account_number;

public:
    Account(){};
    Account(int account_number)
    {
        this->account_number = account_number;
    }
    void display() const // const member function
    {
        std::cout << this->account_number;
    }

    void set_account_number(int account_number) // non-constant function
    {
        this->account_number = account_number;
    }
};

int main()
{
    const Account obj(45566); // constant object
    Account obj2;             // non -constant object
    obj.display();
    // obj.set_account_number(2222); :- error  as set_account_number is non-const function
    obj2.set_account_number(23131); // obj2 is not constant object
    return 0;
}