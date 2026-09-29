# Bank Account Class 

A C++ class for representing a bank account in a banking system.

## Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `accountNumber` | `std::string` | Unique alphanumeric identifier for the account. |
| `accountHolderName` | `std::string` | Full name of the account holder. |
| `Balance` | `double` | Current monetary balance stored in the account. |

## Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `BankAccount()` | (Constructor) | Default constructor. |
| `BankAccount(accNum, accHolder, initialBalance)` | (Constructor) | Parameterized constructor. |
| `getAccountNumber() const` | `std::string` | Gets the account number. |
| `getAccountHolderName() const` | `std::string` | Gets the account holder's name. |
| `getBalance() const` | `double` | Gets the current balance. |
| `setAccountHolderName(newName)` | `void` | Updates the account holder's name. |
| `deposit(amount)` | `void` | Adds funds to the account if amount is positive. |
| `withdraw(amount)` | `void` | Deducts funds if positive and sufficient balance exists. |