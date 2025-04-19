#include <iostream>
#include <string>
#include <exception>
using namespace std;

//Custom Exceptions
class InsufficientFundsException : public exception {
public:
    const char* what() const throw() {
        return "Error: Insufficient funds!";
    }
};

class InvalidTransactionException : public exception {
public:
    const char* what() const throw() {
        return "Error: Invalid transaction!";
    }
};

class DivideByZeroException : public exception {
public:
    const char* what() const throw() {
        return "Error: Cannot divide by zero!";
    }
};

//BankAccount Class
class BankAccount {
private:
    string ownerName;
    double balance;

public:
    //Constructor
    BankAccount(string name, double initialDeposit) {
        if (initialDeposit < 0)
            throw InvalidTransactionException();
        ownerName = name;
        balance = initialDeposit;
        cout << "Creating Account for " << ownerName << " with Initial Deposit: rs" << balance << endl;
    }

    //Deposit
    void deposit(double amount) {
        if (amount < 0)
            throw InvalidTransactionException();
        balance += amount;
        cout << "Depositing rs" << amount << " into " << ownerName << "'s Account\n";
    }

    //Withdraw
    void withdraw(double amount) {
        if (amount < 0)
            throw InvalidTransactionException();
        if (amount > balance)
            throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawing rs" << amount << " from " << ownerName << "'s Account\n";
    }

    //Transfer to another account
    void transfer(BankAccount& to, double amount) {
        if (amount < 0)
            throw InvalidTransactionException();
        if (amount > balance)
            throw InsufficientFundsException();
        balance -= amount;
        to.balance += amount;
        cout << "Transferring rs" << amount << " from " << ownerName << " to " << to.ownerName << endl;
    }

    //Divide balance
    void divideBalance(double divisor) {
        if (divisor == 0)
            throw DivideByZeroException();
        double result = balance / divisor;
        cout << "Balance of " << ownerName << " after dividing by " << divisor << ": rs" << result << endl;
    }

    //Display
    void display() {
        cout << ownerName << "'s Balance: rs" << balance << endl;
    }
};

//Main Function
int main() {
    try {
        BankAccount kaushal("Kaushal Kalas", 50000);
        BankAccount saklen("Saklen Manjire", 40000);

        kaushal.deposit(1000);

        //Attempt to withdraw more than balance
        try {
            kaushal.withdraw(7000);
        } catch (exception& e) {
            cout << e.what() << endl;
        }

        //Valid transfer
        kaushal.transfer(saklen, 3000);
        kaushal.display();
        saklen.display();

        //Divide by zero
        try {
            kaushal.divideBalance(0);
        } catch (exception& e) {
            cout << e.what() << endl;
        }

        //Invalid deposit
        try {
            kaushal.deposit(-100);
        } catch (exception& e) {
            cout << e.what() << endl;
        }

    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

