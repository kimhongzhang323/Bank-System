// Bank.h
#ifndef BANK_H
#define BANK_H

#include <string>

void CreateAccount();
void viewAccount(const std::string& accountID);

class Account {
private:
    std::string name;
    int accountNumber; 
    std::string accountID;
    double balance; 

public:
    // Constructor
    Account(std::string name, int accountNumber, std::string accountID, double balance);

    // Getters
    std::string getName() const;
    int getAccountNumber() const;
    std::string getAccountID() const;
    double getBalance() const;

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
};

// Function declarations
std::string generateAccountID();
void saveAccountToFile(const Account &account);
int generateUniqueAccountNumber();

#endif // BANK_H
