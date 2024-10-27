#include <iostream>
#include <string>
#include <memory>

// Abstract base class for Discount
class Discount
{
public:
    virtual double calculate(double amount) const = 0;
    virtual ~Discount() = default;
};

// Regular customer discount (5%)
class RegularDiscount : public Discount
{
public:
    double calculate(double amount) const override
    {
        return amount * 0.05;
    }
};

// VIP customer discount (10%)
class VIPDiscount : public Discount
{
public:
    double calculate(double amount) const override
    {
        return amount * 0.10;
    }
};

// Discount calculator that uses a Discount strategy
class DiscountCalculator
{
private:
    std::shared_ptr<Discount> discountStrategy;

public:
    DiscountCalculator(std::shared_ptr<Discount> discountStrategy) : discountStrategy(discountStrategy) {}

    double calculateDiscount(double amount) const
    {
        return discountStrategy->calculate(amount);
    }
};

int main()
{
    // Create a calculator with VIPDiscount
    std::shared_ptr<Discount> vipDiscount = std::make_shared<VIPDiscount>();
    DiscountCalculator calculator(vipDiscount);
    double discount = calculator.calculateDiscount(100.0);
    std::cout << "Discount: " << discount << std::endl;

    // Create a calculator with RegularDiscount
    std::shared_ptr<Discount> regularDiscount = std::make_shared<RegularDiscount>();
    DiscountCalculator calculator2(regularDiscount);
    double discount2 = calculator2.calculateDiscount(100.0);
    std::cout << "Discount: " << discount2 << std::endl;

    return 0;
}
