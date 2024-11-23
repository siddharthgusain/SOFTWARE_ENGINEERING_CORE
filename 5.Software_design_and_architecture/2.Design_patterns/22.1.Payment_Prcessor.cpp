#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Strategy Interface
class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategy: Credit Card Payment
class CreditCardPayment : public PaymentStrategy
{
private:
    string cardNumber;

public:
    explicit CreditCardPayment(const string &cardNumber) : cardNumber(cardNumber) {}

    void pay(double amount) override
    {
        cout << "Paid $" << amount << " using Credit Card (" << cardNumber << ")." << endl;
    }
};

// Concrete Strategy: PayPal Payment
class PayPalPayment : public PaymentStrategy
{
private:
    string email;

public:
    explicit PayPalPayment(const string &email) : email(email) {}

    void pay(double amount) override
    {
        cout << "Paid $" << amount << " using PayPal (" << email << ")." << endl;
    }
};

// Concrete Strategy: Google Pay Payment
class GooglePayPayment : public PaymentStrategy
{
private:
    string phoneNumber;

public:
    explicit GooglePayPayment(const string &phoneNumber) : phoneNumber(phoneNumber) {}

    void pay(double amount) override
    {
        cout << "Paid $" << amount << " using Google Pay (" << phoneNumber << ")." << endl;
    }
};

// Context: PaymentProcessor
class PaymentProcessor
{
private:
    shared_ptr<PaymentStrategy> strategy;

public:
    void setStrategy(shared_ptr<PaymentStrategy> newStrategy)
    {
        strategy = newStrategy;
    }

    void processPayment(double amount)
    {
        if (strategy)
        {
            strategy->pay(amount);
        }
        else
        {
            cout << "Payment strategy is not set!" << endl;
        }
    }
};

// Main function demonstrating the Strategy Pattern
int main()
{
    PaymentProcessor processor;

    // Use Credit Card payment
    processor.setStrategy(make_shared<CreditCardPayment>("1234-5678-9876-5432"));
    processor.processPayment(150.75);

    // Switch to PayPal payment
    processor.setStrategy(make_shared<PayPalPayment>("user@example.com"));
    processor.processPayment(89.99);

    // Switch to Google Pay payment
    processor.setStrategy(make_shared<GooglePayPayment>("+123456789"));
    processor.processPayment(50.00);

    return 0;
}
