#include <iostream>
#include <memory>
#include <string>

// Component Interface
class Coffee
{
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component: Basic Coffee
class BasicCoffee : public Coffee
{
public:
    std::string getDescription() const override
    {
        return "Basic Coffee";
    }

    double getCost() const override
    {
        return 2.0; // Base price of coffee
    }
};

// Decorator: Abstract class for Coffee add-ons
class CoffeeDecorator : public Coffee
{
protected:
    std::shared_ptr<Coffee> coffee; // Composition: wraps a Coffee object

public:
    explicit CoffeeDecorator(const std::shared_ptr<Coffee> &coffee) : coffee(coffee) {}
};

// Concrete Decorator 1: Milk
class MilkDecorator : public CoffeeDecorator
{
public:
    explicit MilkDecorator(const std::shared_ptr<Coffee> &coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", Milk";
    }

    double getCost() const override
    {
        return coffee->getCost() + 0.5; // Add cost of milk
    }
};

// Concrete Decorator 2: Sugar
class SugarDecorator : public CoffeeDecorator
{
public:
    explicit SugarDecorator(const std::shared_ptr<Coffee> &coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", Sugar";
    }

    double getCost() const override
    {
        return coffee->getCost() + 0.2; // Add cost of sugar
    }
};

// Concrete Decorator 3: Caramel
class CaramelDecorator : public CoffeeDecorator
{
public:
    explicit CaramelDecorator(const std::shared_ptr<Coffee> &coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", Caramel";
    }

    double getCost() const override
    {
        return coffee->getCost() + 0.7; // Add cost of caramel
    }
};

int main()
{
    // Base coffee
    std::shared_ptr<Coffee> basicCoffee = std::make_shared<BasicCoffee>();
    std::cout << basicCoffee->getDescription() << " costs $" << basicCoffee->getCost() << std::endl;

    // Coffee with Milk
    std::shared_ptr<Coffee> coffeeWithMilk = std::make_shared<MilkDecorator>(basicCoffee);
    std::cout << coffeeWithMilk->getDescription() << " costs $" << coffeeWithMilk->getCost() << std::endl;

    // Coffee with Milk and Sugar
    std::shared_ptr<Coffee> coffeeWithMilkAndSugar = std::make_shared<SugarDecorator>(coffeeWithMilk);
    std::cout << coffeeWithMilkAndSugar->getDescription() << " costs $" << coffeeWithMilkAndSugar->getCost() << std::endl;

    // Coffee with Milk, Sugar, and Caramel
    std::shared_ptr<Coffee> fancyCoffee = std::make_shared<CaramelDecorator>(coffeeWithMilkAndSugar);
    std::cout << fancyCoffee->getDescription() << " costs $" << fancyCoffee->getCost() << std::endl;

    return 0;
}
