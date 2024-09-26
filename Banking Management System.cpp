#include <iostream>
using namespace std;

class Account{
protected:
    string accountHolder;
    double balance;

public:
    Account(string holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    virtual void deposit(double amount)
    {
        balance = balance + amount;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
            {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    virtual void displayBalance()
    {
        cout << "Account holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;
public:
    SavingsAccount(string holder, double initialBalance, double rate)
        : Account(holder, initialBalance), interestRate(rate) {}

    void applyInterest()
    {
        balance += balance  * (interestRate / 100);
    }

    void displayBalance() override
    {
        cout << "Savings Account Balance: $" << balance << endl;
    }
};

class CheckingAccount : public Account
{
private:
    double transactionFee;

public:
    CheckingAccount(string holder, double initialBalance, double fee)
        : Account(holder, initialBalance), transactionFee(fee) {}

    void withdraw(double amount) override
    {
        if (amount + transactionFee <= balance)
        {
            balance -= (amount + transactionFee);
        }
        else
        {
            cout << "Insufficient balance including transaction fee!" << endl;
        }
    }

    void displayBalance() override
    {
        cout << "Checking Account Balance: $" << balance << endl;
    }
};

int main()
{
    SavingsAccount savings("John Doe", 1000.0, 2.0);
    savings.deposit(200);
    savings.applyInterest();
    savings.displayBalance();

    cout << endl;

    CheckingAccount checking("Jane Doe", 500.0, 5.0);
    checking.deposit(100);
    checking.withdraw(50);
    checking.displayBalance();

    return 0;
}


