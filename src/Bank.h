#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

class Account {
public:
    Account(std::string name, int accountNumber, std::string accountID, double balance);
    
    std::string getName() const;
    int getAccountNumber() const;
    std::string getAccountID() const;
    double getBalance() const;

    void deposit(double amount);
    void withdraw(double amount);

private:
    std::string name;
    int accountNumber;
    std::string accountID;
    double balance;
};

class Bank {
public:
    void CreateAccount();
    void viewAccount(const std::string& accountID);
    int generateUniqueAccountNumber();
    std::string generateAccountID();

private:
    std::vector<Account> accounts; // Store accounts in memory
};

#endif // BANK_H
