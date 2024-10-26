#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string owner;
    double balance;

public:
    // Constructor
    BankAccount(string ownerName, double initialBalance) : owner(ownerName), balance(initialBalance) {}

    // Display account information
    void display() const
    {
        cout << "Owner: " << owner << ", Balance: $" << balance << endl;
    }

    // Friend function declaration
    friend bool transferFunds(BankAccount &from, BankAccount &to, double amount);
};

// Friend function to transfer funds between two accounts
bool transferFunds(BankAccount &from, BankAccount &to, double amount)
{
    if (from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer successful: $" << amount << " from " << from.owner << " to " << to.owner << endl;
        return true;
    }
    else
    {
        cout << "Transfer failed: Insufficient balance in " << from.owner << "'s account." << endl;
        return false;
    }
}

int main()
{
    BankAccount account1("Alice", 500.0);
    BankAccount account2("Bob", 300.0);

    cout << "Initial Balances:\n";
    account1.display();
    account2.display();

    // Perform a fund transfer
    transferFunds(account1, account2, 200.0);

    cout << "\nBalances After Transfer:\n";
    account1.display();
    account2.display();

    return 0;
}
