#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;
    string dates[100];
    string types[100];
    double amounts[100];
    double balances[100];
    int transactionCount;

public:
    BankAccount() {
        balance = 0.0;
        transactionCount = 0;
    }

    void deposit(double amount, string date) {
        balance += amount;
        if (transactionCount < 100) {
            dates[transactionCount] = date;
            types[transactionCount] = "Deposit";
            amounts[transactionCount] = amount;
            balances[transactionCount] = balance;
            transactionCount++;
        }
        cout << "Deposit successful! New balance: " << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount, string date) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            if (transactionCount < 100) {
                dates[transactionCount] = date;
                types[transactionCount] = "Withdraw";
                amounts[transactionCount] = amount;
                balances[transactionCount] = balance;
                transactionCount++;
            }
            cout << "Withdrawal successful! New balance: " << fixed << setprecision(2) << balance << endl;
        }
    }

    void printMiniStatement() {
        cout << "\n---- Statement ----\n";
        cout << left << setw(12) << "Date" << setw(10) << "Type" << setw(10) << "Amount" << setw(10) << "Balance" << endl;
        cout << "--------------------------------------" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << left << setw(12) << dates[i] << setw(10) << types[i] 
                 << setw(10) << fixed << setprecision(2) << amounts[i] 
                 << setw(10) << balances[i] << endl;
        }
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;
    string date;

    do {
        cout << "\nBank Menu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Print Mini Statement\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter date (DD-MM-YYYY): ";
                cin >> date;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount, date);
                break;
            case 2:
                cout << "Enter date (DD-MM-YYYY): ";
                cin >> date;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount, date);
                break;
            case 3:
                account.printMiniStatement();
                break;
            case 4:
                cout << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

