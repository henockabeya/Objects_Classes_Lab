/*******************************************************************************************************************************
* Name: Henoc Kabeya
* Date: September 28, 2026
Purpose:
 *     - Encapsulate individual account state within a BankAccount class.
 *     - Manage a dynamic list of BankAccount objects using std::vector.
 *     - Provide an interactive, menu-driven CLI for account creation,
 *       deposits, withdrawals, and account record retrieval.

* Organization of the program:

 *   Basic Logic & Implementation Documentation:
 *     1. Class BankAccount:
 *        - Private attributes: accountNumber, accountHolderName, Balance.
 *        - Constructors: Default (empty/zero initialization) and Parameterized.
 *        - Accessors: Read-only getters for all three data members.
 *        - Mutator: Public setter for updating accountHolderName.
 *        - Banking Methods:
 *            * deposit(): Validates positive deposit amount before adding to balance.
 *            * withdraw(): Validates positive amount and checks for sufficient
 *              funds before deducting from balance.
 *
 *     2. Main Controller Flow:
 *        - Allocates std::vector<BankAccount> accounts to dynamically store records.
 *        - Encloses the console UI within a do-while loop controlled by choice != 5.
 *        - Validates numeric menu input via cin stream checking (clears failbit and
 *          discards invalid tokens with numeric_limits<streamsize>::max()).
 *        - Uses a switch statement with scoped case blocks to handle options:
 *            * Case 1: Prompts for details, instantiates BankAccount, appends via push_back().
 *            * Case 2: Linear search by accountNumber; invokes deposit() if matched.
 *            * Case 3: Linear search by accountNumber; invokes withdraw() if matched.
 *            * Case 4: Linear search by accountNumber; prints account details if matched.
 *            * Case 5: Displays farewell message and terminates the loop.
********************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Definition of my class

class BankAccount {

    // Declaration of my private members
    private:
    string accountNumber;
    string accountHolderName;
    double Balance;

    // Declaration and initialization of my default constructor
    public:
    BankAccount() {
        accountNumber = "";
        accountHolderName = "";
        Balance = 0.0;
    }

    // Declaration and initialization of my parametrized constructor
    BankAccount(string accNum, string accHolder, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        Balance = initialBalance;
    }

    // Implementation of public accessors
    string getAccountNumber() const{
        return accountNumber;
    }
    string getAccountHolderName() const {
        return accountHolderName;
    }
    double getBalance() const {
        return Balance;
    }

    // Implementation of public mutator
    void setAccountHolderName(string newName) {
        accountHolderName = newName;
    }

    // Banking Operations
    void deposit(double amount) {
        if (amount > 0.0) {
            Balance += amount;
            cout << "The deposit was successfully process." << endl;
        }
        else {
            cout << "The deposit was unsuccessfully. It must be positive" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "The withdrawal must be positive. Please, try again." << endl;
        }
        else if (amount > Balance) {
            cout << "Error. Insufficient funds in the account." << endl;
        }
        else {
            Balance -= amount;
        }
    }
};

int main() {
    // Dynamic array to store multiple customer accounts
    vector<BankAccount> accounts;
    int choice = 0;
    do {
        // Display Menu Options
        cout << "\n=========================================\n";
        cout << "               Bank of Modesto             \n";
        cout << "===========================================\n";
        cout << "1. Create a New Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Display Account Details " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice(1-5): ";

        // Menu choice validation
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            // Case 1 for accounts creation
            case 1: {
                string accNum, accHolder;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account full name: ";
                cin.ignore();
                getline(cin, accHolder);
                cout << "Enter initial balance: ";
                cin >> initialBalance;

                BankAccount newAccount(accNum, accHolder, initialBalance);
                accounts.push_back(newAccount);

                cout << "Your account has been successfully created." << endl;
                break;
            }
            // Case2 for funds deposit
            case 2: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;
                for (auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        account.deposit(amount);

                    }
                }
                if (!found) {
                    cout << "Account number not found. Please try again." << endl;
                }
                break;
            }
            // Case 3 for the funds withdrawal
            case 3: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;

                for (auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        account.withdraw(amount);
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found. Please try again." << endl;
                }
                break;
            }
            // Case 4 for showing the account's details
            case 4: {
                string searchAccNum;
                cout << "Enter account number: ";
                cin >> searchAccNum;

                bool found = false;
                for (const auto & account : accounts) {
                    if (account.getAccountNumber() == searchAccNum) {
                        found = true;
                        cout << "\nAccount Found:\n";
                        cout << "Account Number: " << account.getAccountNumber() << endl;
                        cout << "Account Holder: " << account.getAccountHolderName() << endl;
                        cout << "Account Balance: $" << account.getBalance() << endl;
                        break;
                    }
                }

                if (!found) {
                    cout << "Account not found." << endl;
                }
                break;
            }
            // Exit the program
            case 5:
                cout << "Thank you for choosing Bank of Modesto." << endl;
                break;
            default:
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            break;
        }
        } while (choice != 5);
            return 0;
}
