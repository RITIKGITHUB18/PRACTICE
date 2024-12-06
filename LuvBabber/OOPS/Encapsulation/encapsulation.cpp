/**
 * Encapsulation is one of the four core principles of Object-Oriented Programming (OOP).
 * It refers to the practice of bundling data (fields) and methods (functions) that operate on that data into a single unit,
 * usually a class, and restricting direct access to some of the object's components.
 * This ensures that the internal details of an object are hidden,
 * and only a well-defined interface is exposed to interact with it.
 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    // Private data members
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(string name, double initialBalance)
    {
        accountHolderName = name;
        balance = initialBalance;
    }

    // Getter for account holder's name
    string getAccountHolderName()
    {
        return accountHolderName;
    }

    // Getter for balance
    double getBalance()
    {
        return balance;
    }

    // Setter for depositing money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Setter for withdrawing money
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

int main()
{
    // Creating a bank account
    BankAccount account("John Doe", 500.0);

    // Accessing data through the public interface
    cout << "Account Holder: " << account.getAccountHolderName() << endl;
    cout << "Current Balance: $" << account.getBalance() << endl;

    // Depositing money
    account.deposit(200.0);

    // Withdrawing money
    account.withdraw(100.0);

    // Attempting an invalid withdrawal
    account.withdraw(1000.0);

    cout << "Final Balance: $" << account.getBalance() << endl;

    return 0;
}
