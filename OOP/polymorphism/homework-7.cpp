    #include <iostream>
    #include <string>

    using namespace std;

    /*
        Exercise: Implement a Banking System

        In this exercise, you will create a basic banking system with the following classes:

        1. Account (Base Class):
            Create a base class called Account with the following attributes and methods:
            - accountNumber (integer)
            - balance (double)
            - Account(const int accountNumber, const double balance) constructor.
            - A virtual destructor for proper resource cleanup.
            - virtual void deposit(double amount) method to deposit funds into the account.
            - virtual void withdraw(double amount) method to withdraw funds from the account.
            - virtual void displayBalance() method to display the current balance.

        2. SavingsAccount (Derived Class):
            Create a derived class called SavingsAccount that inherits from Account. This class should include:
            - A constructor that takes an account number, initial balance, and an interest rate (e.g., 3%).
            - An overridden displayBalance() method that displays the current balance along with the interest rate.
            - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so,
            processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
        3.  CheckingAccount (Derived Class):
            - Create another derived class called CheckingAccount that inherits from Account. This class should include:
            - A constructor that takes an account number and initial balance.
            - An overridden displayBalance() method that displays the current balance along with a message indicating it's a checking account.
            - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so,
            processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
        4. Main Function:
            - In the main() function, create instances of both SavingsAccount and CheckingAccount.
            - Deposit and withdraw funds from these accounts, and display their balances to demonstrate polymorphism.

        5. Proper Cleanup:
        - Make sure to delete the account objects at the end of the main() function to ensure that their destructors are called.
    */

    class Account
    {
    private:
        int accountNumber;
        double balance;

    public:
        // Constructor, virtual destructor, and methods go here
        Account(const int accountNumber, const double balance)
            : accountNumber(accountNumber), balance(balance) {}
        virtual ~Account() {}
        virtual void deposit(double amount)
        {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
            cout << endl;
        }
        virtual void withdraw(double amount)
        {
            if (amount <= balance)
            {
                balance -= amount;
                cout << "Withdrew " << amount << ". New balance: " << balance << endl;
                cout << endl;
            }
            else
            {
                cout << "Error: Insufficient funds for withdrawal of " << amount << endl;
                cout << endl;
            }
        }
        virtual void displayBalance()
        {
            cout << "Account Balance: " << balance << endl;
            cout << endl;
        }
    };

    class SavingsAccount : public Account
    {
    private:
        double interestRate;

    public:
        // Constructor and overridden methods go here
        SavingsAccount(const int accountNumber, const double balance, const double interestRate)
            : Account(accountNumber, balance), interestRate(interestRate) {}
        void displayBalance() override
        {
            cout << "Savings Account Balance: ";
            Account::displayBalance();
            cout << "Interest Rate: " << interestRate << "%" << endl;
        }
        void withdraw(double amount) override
        {
            Account::withdraw(amount);
        }
    };

    class CheckingAccount : public Account
    {
    public:
        // Constructor and overridden methods go here
        CheckingAccount(const int accountNumber, const double balance)
            : Account(accountNumber, balance) {}
        void displayBalance() override
        {
            cout << "Checking Account Balance: ";
            Account::displayBalance();
        }
        void withdraw(double amount) override
        {
            Account::withdraw(amount);
        }
    };

    int main()
    {
        // Create instances of SavingsAccount and CheckingAccount
        // Deposit and withdraw funds, display balances
        // Properly clean up objects

        // Erase:
        int numberofsaving = 3;
        int numberofchecking = 2;
        // Create SavingsAccount and CheckingAccount instances
        // Account* savings = new SavingsAccount(1001, 1000.0, 3.0); // Account Number, Initial Balance, Interest Rate
        // Account* checking = new CheckingAccount(2001, 2000.0);     // Account Number, Initial Balance

        // Deposit and withdraw funds from accounts
        Account *savingsAccounts[numberofsaving];
        savingsAccounts[0] = new SavingsAccount(1001, 1000.0, 3.0);
        savingsAccounts[1] = new SavingsAccount(1002, 1500.0, 2.5);
        savingsAccounts[2] = new SavingsAccount(1003, 2000.0, 4.0);
        Account *checkingAccounts[numberofchecking];
        checkingAccounts[0] = new CheckingAccount(2001, 2000.0);
        checkingAccounts[1] = new CheckingAccount(2002, 2500.0);
        // Perform some transactions
        savingsAccounts[0]->deposit(500.0);
        savingsAccounts[0]->withdraw(200.0);
        savingsAccounts[0]->withdraw(2000.0); // This should display an error message
        checkingAccounts[0]->deposit(300.0);
        checkingAccounts[0]->withdraw(100.0);
        checkingAccounts[0]->withdraw(3000.0);

        // This should display an error message

        // Display balances using polymorphism
        for (int i = 0; i < numberofsaving; i++)
        {
            savingsAccounts[i]->displayBalance();
        }
        for (int i = 0; i < numberofchecking; i++)
        {
            checkingAccounts[i]->displayBalance();
        }

        // Properly clean up objects

        for (int i = 0; i < numberofsaving; i++)
        {
            cout << "deleting... account of " << i << endl;

            delete savingsAccounts[i];
        }
        for (int i = 0; i < numberofchecking; i++)
        {
            cout << "deleting... account of " << i << endl;

            delete checkingAccounts[i];
        }
        return 0;
    }
