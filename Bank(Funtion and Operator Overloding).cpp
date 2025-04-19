#include <iostream>
#include <string>
using namespace std;

//Function Overloading: Bank class
class Bank {
public:
    void deposit(int amount) {
        cout << "Depositing rs" << amount << " in cash." << endl;
    }

    void deposit(float amount) {
        cout << "Depositing rs" << amount << " via digital payment." << endl;
    }

    void deposit(string upiID) {
        cout << "Depositing rs2500 using UPI (" << upiID << ")." << endl;
    }
};

//Operator Overloading: Account class
class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    //Overload + to transfer funds between accounts
    void operator+(Account& other) {
        double amount;
        cout << "Enter amount to transfer from Account " << accountNumber << " to Account " << other.accountNumber << ": rs";
        cin >> amount;

        if (balance >= amount) {
            balance -= amount;
            other.balance += amount;
            cout << "Transferred rs" << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance to transfer.\n";
        }
    }

    //Overload - to withdraw funds
    void operator-() {
        double amount;
        cout << "Enter amount to withdraw from Account " << accountNumber << ": rs";
        cin >> amount;

        if (balance >= amount) {
            balance -= amount;
            cout << "Withdraw rs" << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance to withdraw.\n";
        }
    }

    void display() {
        cout << "Account " << accountNumber << " Balance: rs" << balance << endl;
    }
};

//Main function
int main() {
    //Function Overloading Demonstration
    Bank b;
    b.deposit(5000);
    b.deposit(1500.75f);
    b.deposit("gpay@upi");

    cout << "\n";

    //Operator Overloading Demonstration
    Account acc1(1, 10000);
    Account acc2(2, 5000);

    acc1.display();
    acc2.display();

    cout << "\nTransferring rs3000 from Account 1 to Account 2...\n";
    acc1 + acc2;

    acc1.display();
    acc2.display();

    cout << "\nWithdrawing rs2000 from Account 1...\n";
    -acc1;

    acc1.display();

    return 0;
}

