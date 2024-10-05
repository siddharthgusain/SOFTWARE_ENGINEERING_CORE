#include <iostream>

class Employee
{
    int salary;

public:
    void setSalary(int salary);
    friend float get_income_tax(Employee e); // declaring friend function
};

void Employee::setSalary(int salary)
{
    this->salary = salary;
}

float get_income_tax(Employee e)
{
    float income_tax;
    income_tax = 0.3 * e.salary; // accessing private variable "salary"
    return income_tax;
}

int main()
{
    Employee e;
    e.setSalary(100);
    std::cout << get_income_tax(e); // friend function called
    return 0;
}