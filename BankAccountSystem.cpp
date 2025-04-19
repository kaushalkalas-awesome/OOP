#include <iostream>
using namespace std;

//Define the BankAccount class
class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    //Default Constructor
    BankAccount() {
        accountHolder = "Undefined";
        accountNumber = 0;
        accountType = "Savings";
        balance = 0.0;
    }

    //Parameterized Constructor
    BankAccount(string name, int number, string type, double initialBalance) {
        accountHolder = name;
        accountNumber = number;
        accountType = type;
        balance = initialBalance;
    }

    //Accessor (Getter) Methods
    string getAccountHolder() {
        return accountHolder;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountType() {
        return accountType;
    }

    double getBalance() {
        return balance;
    }

    //Mutator (Setter) Method
    void setAccountType(string newType) {
        accountType = newType;
        cout << "Updated Account Type to " << accountType << "." << endl;
    }

    //Deposit Function
    void deposit(double amount) {
        if (amount > 0) {
            cout << "Depositing " << amount << "..." << endl;
            balance += amount;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    //Withdraw Function
    void withdraw(double amount) {
        if (amount <= balance) {
            cout << "Withdrawing " << amount << "..." << endl;
            balance -= amount;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    //Display Account Details
    void displayAccountDetails() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

//Main function 
int main() {
    //Creating first account
    BankAccount account1;
    cout << "Default Account:" << endl;
    account1.displayAccountDetails();

    cout << "\n---------------------------\n";

    //Getting input from user to create second account
    string name, type;
    int number;
    double initial;

    cout << "Enter details to create a new account:\n";
    cout << "Account Holder Name: ";
    getline(cin, name);
    cout << "Account Number: ";
    cin >> number;
    cout << "Account Type (Savings/Current): ";
    cin >> type;
    cout << "Initial Balance: ";
    cin >> initial;

    //Creating second account using parameterized constructor
    BankAccount account2(name, number, type, initial);

    //Displaying account details
    account2.displayAccountDetails();

    //Performing deposit
    double depositAmt;
    cout << "\nEnter amount to deposit: ";
    cin >> depositAmt;
    account2.deposit(depositAmt);

    //Performing withdrawal
    double withdrawAmt;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmt;
    account2.withdraw(withdrawAmt);

    //Modifying account type
    string newType;
    cout << "Enter new account type: ";
    cin >> newType;
    account2.setAccountType(newType);

    //Displaying final details
    cout << "\nFinal Account Details:";
    account2.displayAccountDetails();

    return 0;
}

