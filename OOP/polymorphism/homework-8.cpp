#include <iostream>
#include <string>

using namespace std;


/*
    Static Keyword in C++
*/


/*
    Exercise-1: Stock Price Tracker

    Write a C++ program that simulates a stock price tracker function. 
    The stock price tracker function should have the following properties:

    1. Create a function named trackStockPrice that takes the stock symbol (a string) and the current stock price (a double) as parameters.
    2. Inside the function, maintain a static local variable that stores the highest stock price observed for a given stock symbol.
    3. Update the highest stock price if the current price is higher.
    4. The function should return the highest stock price observed for the given stock symbol.


*/
//         string author;
//     static double highestPrice = 0.0;
// double trackStockPrice(string symbol, double currentPrice) {

//     if (currentPrice > highestPrice) {
//         highestPrice = currentPrice;
//     author = symbol + " ";
//     }
    
//     return highestPrice;
// }   ;
//     // your code



/*
    Exercise-2: Bank Account Management

    Create a C++ program that models a simplified bank account management system. 
    In this system, you will create a BankAccount class with the following features:

    1. Each BankAccount object should have a unique account number that starts from 1001 and increments by 1 for each new account created.
    2. Each account should have an account balance.
    3. Implement methods to deposit and withdraw funds from the account.
    4. Implement a method to display the account details, including the account number and balance.
    */
   static  int countAcc=0;
   static int nextAccountNumber=1001; // Static member to keep track of the next account number
   class BankAccount {
       // your code
       private:
       
       // Initialize static member
       int accountNumber=1001;
       double balance;
       public:
       static int totalAccounts() {
           return countAcc;
       }

        BankAccount() : balance(0.0) {
            accountNumber = nextAccountNumber++;
            countAcc++;
        }
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
        void withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrew: $" << amount << endl;
            } else {
                cout << "Insufficient funds for withdrawal of $" << amount << endl;
            }
        }
        void displayAccountDetails() const {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Balance: $" << balance << endl;
        }   
     // Static member to keep track of total accounts created
            
            
};



/*
    Exercise-3: One instance Class

    Create a C++ program that implements a  class, 
    which ensures that only one instance(object) of the class can be created. 
*/
class OnlyOneInstance {
    // your code
    private:
        static OnlyOneInstance *instance; 
        OnlyOneInstance() {}

    public:
        OnlyOneInstance(const OnlyOneInstance &obj) = delete;
        
        static OnlyOneInstance *getInstance() {
            if (instance == nullptr) {
                instance = new OnlyOneInstance();
                cout << "Creating new instance." << endl;
                return instance;
            } else {
                cout << "Instance already exists. Returning existing instance." << endl;
                return instance;
            }
        }
};

OnlyOneInstance *OnlyOneInstance::instance = nullptr;


/*
    Exercise-4: Prime Number Caching

    Objective:
    Write a C++ program that efficiently generates and caches prime numbers up to 100 and allows you to query the cached prime numbers.

    Requirements:
    1. Implement a function that generates prime numbers up to 100(e.g., generatePrimes(int limit)).
    2. Cache the generated prime numbers for quick retrieval.
    4. Create a menu-driven user interface to interact with the caching system.
    5. Generate and cache prime numbers up to a specified limit.
    6. Check if a number is prime using the cached data.
// */
static int primes[100] = {0};   // Static cache for Prime numbers

void generateAndCachePrimes(int limit) {
    // your code
    int count = 0;
    for (int num = 2; num <= limit; ++num) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
            else{
                isPrime = true;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
    }
}






// int main() {
//     BankAccount account1;
//     account1.deposit(1000);
//     account1.withdraw(500);
//     account1.displayAccountDetails();

//     BankAccount account2;
//     account2.deposit(1500);
//     account2.displayAccountDetails();

//     // Display the total number of accounts created.
//     std::cout << "Total Accounts Created: " << BankAccount::totalAccounts << std::endl;

//     return 0;
// }




int main() {

    //  Exercise-1: example usage
    // double price1 = trackStockPrice("AAPL", 150.25);
    // // cout << "Highest AAPL Stock Price: $" << price1 << endl;

    // double price2 = trackStockPrice("GOOGL", 2700.50);
    // // cout << "Highest GOOGL Stock Price: $" << price2 << endl;

    // double price3 = trackStockPrice("AAPL", 155.75);
    // // cout << "Highest AAPL Stock Price: $" << price3 << endl;

    // double price4 = trackStockPrice("TSLA", 8000.00);
    // // cout << "Highest TSLA Stock Price: $" << price4 << endl;
    // cout << "Tracking " << author << "Highest Price = " << highestPrice << endl;
    // //  Exercise-2: example usage
    // BankAccount account1;
    // account1.deposit(1000);
    // account1.withdraw(500);
    // account1.displayAccountDetails();

    // BankAccount account2;
    // account2.deposit(1500);
    // account2.displayAccountDetails();

    // // Display the total number of accounts created.
    // cout << "Total Accounts Created: " << BankAccount::totalAccounts() << endl;



    // Exercise-3: example usage
    // your code ;-)
    // OnlyOneInstance *obj1 = OnlyOneInstance::getInstance();
    // OnlyOneInstance *obj2 = OnlyOneInstance::getInstance();


    // Exercise-4: example usage
    // your code ;-)
    generateAndCachePrimes(100);
cout << "Generating and Caching Prime Numbers up to 100..." << endl;
cout << "give a number!" << endl;
    int x;
    cin >> x;
    cout << "Cached Prime Numbers up to 100:" << endl;
    bool found = false;
    for (int i = 0; i < 100 && primes[i] != 0; ++i) {
        if(primes[i]==x){
           
            found = true;
            break;
        }
            else{
                found = false;
            }
    }
    if(found){
        cout << x << " is a prime number." << endl;
    }else{
        cout << x << " is not a prime number." << endl;
    }
}