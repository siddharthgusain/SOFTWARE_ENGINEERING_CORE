#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TransactionHistory; // Forward declaration

class BankAccount
{
private:
    string owner;
    double balance;

public:
    BankAccount(string ownerName, double initialBalance) : owner(ownerName), balance(initialBalance) {}

    void displayBalance() const
    {
        cout << "Owner: " << owner << ", Balance: $" << balance << endl;
    }

    // Declare TransactionHistory as a friend class
    friend class TransactionHistory;
};

class TransactionHistory
{
private:
    vector<string> transactions;

public:
    // Record a deposit
    void recordDeposit(BankAccount &account, double amount)
    {
        account.balance += amount;
        transactions.push_back("Deposit of $" + to_string(amount) + " to " + account.owner);
        cout << "Deposited $" << amount << " to " << account.owner << "'s account.\n";
    }

    // Record a withdrawal
    bool recordWithdrawal(BankAccount &account, double amount)
    {
        if (account.balance >= amount)
        {
            account.balance -= amount;
            transactions.push_back("Withdrawal of $" + to_string(amount) + " from " + account.owner);
            cout << "Withdrew $" << amount << " from " << account.owner << "'s account.\n";
            return true;
        }
        else
        {
            cout << "Insufficient balance for withdrawal from " << account.owner << "'s account.\n";
            return false;
        }
    }

    // Display all transactions
    void showTransactions() const
    {
        cout << "Transaction History:\n";
        for (const auto &transaction : transactions)
        {
            cout << "- " << transaction << endl;
        }
    }
};

int main()
{
    BankAccount account("Alice", 1000.0);
    TransactionHistory history;

    // Display initial balance
    account.displayBalance();

    // Perform transactions
    history.recordDeposit(account, 200.0);
    history.recordWithdrawal(account, 150.0);
    history.recordWithdrawal(account, 1200.0); // Insufficient balance example

    // Display final balance
    account.displayBalance();

    // Display all transactions
    history.showTransactions();

    return 0;
}
