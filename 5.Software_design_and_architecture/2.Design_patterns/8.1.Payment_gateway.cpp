#include <iostream>
#include <string>
#include <memory>

// Implementor Interface (Payment Gateway)
class PaymentGateway
{
public:
    virtual void processPayment(const std::string &account, double amount) = 0;
    virtual ~PaymentGateway() = default;
};

// Concrete Implementor 1 (Stripe Gateway)
class StripeGateway : public PaymentGateway
{
public:
    void processPayment(const std::string &account, double amount) override
    {
        std::cout << "Processing payment of $" << amount << " using Stripe for account: " << account << std::endl;
    }
};

// Concrete Implementor 2 (Paytm Gateway)
class PaytmGateway : public PaymentGateway
{
public:
    void processPayment(const std::string &account, double amount) override
    {
        std::cout << "Processing payment of $" << amount << " using Paytm for account: " << account << std::endl;
    }
};

// Abstraction (Payment Method)
class PaymentMethod
{
protected:
    PaymentGateway *gateway; // Bridge to the Payment Gateway
public:
    explicit PaymentMethod(PaymentGateway *gateway) : gateway(gateway) {}
    virtual void makePayment(const std::string &account, double amount) = 0;
    virtual ~PaymentMethod() = default;
};

// Refined Abstraction 1 (Credit Card Payment)
class CreditCardPayment : public PaymentMethod
{
public:
    explicit CreditCardPayment(PaymentGateway *gateway) : PaymentMethod(gateway) {}

    void makePayment(const std::string &account, double amount) override
    {
        std::cout << "[Credit Card Payment]\n";
        gateway->processPayment(account, amount);
    }
};

// Refined Abstraction 2 (PayPal Payment)
class PayPalPayment : public PaymentMethod
{
public:
    explicit PayPalPayment(PaymentGateway *gateway) : PaymentMethod(gateway) {}

    void makePayment(const std::string &account, double amount) override
    {
        std::cout << "[PayPal Payment]\n";
        gateway->processPayment(account, amount);
    }
};

int main()
{
    // Create payment gateways
    StripeGateway stripe;
    PaytmGateway paytm;

    // Create payment methods with specific gateways
    CreditCardPayment creditCardPayment(&stripe);
    PayPalPayment payPalPayment(&paytm);

    // Process payments
    std::cout << "Scenario 1: Credit Card via Stripe\n";
    creditCardPayment.makePayment("john_doe_account", 150.00);

    std::cout << "\nScenario 2: PayPal via Paytm\n";
    payPalPayment.makePayment("jane_doe_account", 200.50);

    return 0;
}
