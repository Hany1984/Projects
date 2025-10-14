// 🏦 Bank Account CLI Mini-App
// Description:
// Design a simple Bank Account management system using OOP principles.
// The program should allow users to create a bank account, deposit money, withdraw money (with validation), and view their transaction history. Optionally, allow transferring money between two accounts.
// All account data and transactions should be saved to and loaded from a CSV file using ofstream and ifstream.
// Requirements:
    // Create a class BankAccount with:
        // Private members: ownerName, accountNumber, balance.
        // Public methods:
            // deposit(double amount)
            // withdraw(double amount)
            // printBalance() const
        // Validation:
            // Prevent negative deposits/withdrawals.
            // Prevent withdrawals larger than the current balance.
    // (Optional) Create a class Transaction that logs: type, amount, date.
    // Save and load transactions using CSV files.
    // Implement a menu loop in main():
        // 1. Deposit
        // 2. Withdraw
        // 3. Print balance
        // 4. Print history
        // 5. Exit