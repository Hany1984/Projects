// Project Description:
// Developed a command-line banking system in C++ that allows users to manage personal 
// accounts with full CRUD (Create, Read, Update, Delete) functionality.
// The system includes file-based persistence, enabling accounts to be saved and 
// reloaded across sessions using formatted text files.
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
// ------------------------------Account Class-------------------------------------
class Account
{
    private:
    string firstName;
    string lastName;
    int accountNumber;
    float balance;
    public:
    static long NextAccountNumber;
    Account() {}
    Account(string firstName, string lastName, float balance)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->balance = balance;
        this->accountNumber = NextAccountNumber;
        NextAccountNumber++;
    }
    void setfirstName(string N)
    {
        firstName = N;
    }
    string getfirstName()
    {
        return firstName;
    }
    void setlastName(string lN)
    {
        lastName = lN;
    }
    string getlastName()
    {
        return lastName;
    }
    void Deposit(float amount)
    {
        balance += amount;
    }
    void Withdraw(float amount)
    {
        balance -= amount;
    }
    float getBalance()
    {
        return balance;
    }
    void DisplayAccountDetails()
    {
        cout << "Account Number: " << accountNumber <<endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Balance: " << balance << endl;
    }
    int getAccountNumber()
    {
        return accountNumber;
    }
};
long Account::NextAccountNumber = 1;
// ------------------------------Bank Class-------------------------------------
class Bank
{
    private:
    map<int, Account> accounts;
    public:
    Bank()
    {
    }    
    void OpenAccount()
    {
        string firstName, lastName;
        float deposit;
        cout << "Enter your first name: " << endl;
        cin >> firstName;
        cout << "Enter your last name: " << endl;
        cin >> lastName;
        cout << "Enter initial deposit: " << endl;
        cin >> deposit;
        Account newAccount(firstName, lastName, deposit);
        accounts[newAccount.getAccountNumber()] = newAccount;
        cout << "Account created! Your account number is: " << newAccount.getAccountNumber()<< endl;
    }
    void Deposit(int accountNumber, float amount)
    {
        cout << "Enter account number: " << endl;
        cin >> accountNumber;
        cout << "Enter deposit amount:" << endl;
        cin >> amount;
        if(accounts.find(accountNumber) != accounts.end())
        {
            accounts[accountNumber].Deposit(amount);
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }
    void Withdraw(int accountNumber, float amount)
    {
        cout << "Enter account number: " << endl;
        cin >> accountNumber;
        cout << "Enter withdrawal amount:" << endl;
        cin >> amount;
        if(accounts.find(accountNumber) != accounts.end())
        {
            accounts[accountNumber].Withdraw(amount);
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }
    void BalanceEnquiry(int accountNumber)
    {
        cout << "Enter account number: " << endl;
        cin >> accountNumber;
        if(accounts.find(accountNumber) != accounts.end())
        {
            cout << "Current balance: $" << accounts[accountNumber].getBalance() << endl;
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }
    void CloseAccount(int accountNumber)
    {
        cout << "Enter account number: " << endl;
        cin >> accountNumber;
        if(accounts.find(accountNumber) != accounts.end())
        {
            accounts.erase(accountNumber);
            cout << "Account closed successfully." << endl;
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }
    void DisplayAllAccounts()
    {
        for (auto pair : accounts)
        {
            pair.second.DisplayAccountDetails();
        }
    }
    void SaveAccounts()
    {
        ofstream outfile("accounts.txt");
        for (auto pair : accounts)
        {
            outfile << "Account Number: " << pair.second.getAccountNumber() << endl;
            outfile << "First Name: " << pair.second.getfirstName() << endl;
            outfile << "Last Name: " << pair.second.getlastName() << endl;
            outfile << "Balance: " << pair.second.getBalance() << endl;
            outfile << endl;
        }
        outfile.close();
    }
    void LoadAccounts()
    {
        string line1, line2, line3, line4, blankLine;
        int accountNumber;
        string firstName, lastName;
        float balance;
        ifstream infile("accounts.txt");
        if (!infile)
        {
            cout << "Failed to open file!" << endl;
            return;
        }
        while (getline(infile, line1))
        {
            getline(infile, line2);
            getline(infile, line3);
            getline(infile, line4);
            getline(infile, blankLine);
            // Extract values
            accountNumber = stoi(line1.substr(16));
            firstName = line2.substr(12);
            lastName = line3.substr(11);
            balance = stof(line4.substr(9));
            // Create account and insert into map
            Account newAccount(firstName, lastName, balance);
            accounts[accountNumber] = newAccount;
            // Update static counter if needed
            if (accountNumber >= Account::NextAccountNumber)
                Account::NextAccountNumber = accountNumber + 1;
        }
        infile.close();
    }
};
// -------------------------------Main ------------------------------------
int main()
{
    Bank B;
    B.LoadAccounts();
    int Choice;
    do
    {
        cout << "*** Banking System ***" << endl;
        cout << "Select one option below:" << endl;
        cout << "1. Open an account" << endl;
        cout << "2. Balance Enquiry" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdrawal" << endl;
        cout << "5. Close an account" << endl;
        cout << "6. Show all accounts" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
            case 1:
                B.OpenAccount();
                break;
            case 2:
                B.BalanceEnquiry(0);
                break;
            case 3:
                B.Deposit(0, 0);
                break;
            case 4:
                B.Withdraw(0, 0);
                break;
            case 5:
                B.CloseAccount(0);
                break;
            case 6:
                B.DisplayAllAccounts();
                break;
            case 7:
                B.SaveAccounts();
                cout << "Thank you for using the banking system!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (Choice != 7);
    return 0;
}