#include <iostream>
#include <string>

class DiscountCalculator
{
public:
    double calculateDiscount(const std::string &customerType, double amount)
    {
        if (customerType == "Regular")
        {
            return amount * 0.05; // 5% discount for regular customers
        }
        else if (customerType == "VIP")
        {
            return amount * 0.10; // 10% discount for VIP customers
        }
        else
        {
            return 0.0; // No discount for unknown customer types
        }
    }
};

int main()
{
    DiscountCalculator calculator;
    double discount = calculator.calculateDiscount("VIP", 100.0);
    std::cout << "Discount: " << discount << std::endl;
    return 0;
}

/*
Problems with this Design
Modification Required: To add a new customer type with a different discount rate, we must modify the DiscountCalculator class.
Violation of OCP: Each change requires modifying existing, tested code, increasing the chance of introducing errors.
*/