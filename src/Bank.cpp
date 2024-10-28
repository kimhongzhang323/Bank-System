#include "Bank.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time

// Account class constructor and member function definitions
Account::Account(std::string name, int accountNumber, std::string accountID, double balance)
    : name(std::move(name)), accountNumber(accountNumber), accountID(std::move(accountID)), balance(balance) {}

std::string Account::getName() const { return name; }
int Account::getAccountNumber() const { return accountNumber; }
std::string Account::getAccountID() const { return accountID; }
double Account::getBalance() const { return balance; }

void Account::deposit(double amount) { balance += amount; }
void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Error: Insufficient balance.\n";
    }
}

std::string Bank::generateAccountID() {
    std::string accountID;
    for (int i = 0; i < 10; i++) {
        accountID += std::to_string(rand() % 10);
    }
    return accountID;
}

int Bank::generateUniqueAccountNumber() {
    int accountNumber;
    bool unique;
    
    do {
        unique = true;
        accountNumber = rand() % 1000000;
        
        // Check for uniqueness
        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                unique = false;
                break;
            }
        }
    } while (!unique);

    return accountNumber;
}

void Bank::CreateAccount() {
    std::string name;
    double balance;

    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cerr << "Error: Name cannot be empty.\n";
        return;
    }

    int accountNumber = generateUniqueAccountNumber();
    std::cout << "This is your account number: " << accountNumber << "\n";

    std::cout << "Enter balance: ";
    if (!(std::cin >> balance) || balance < 10) {
        std::cerr << "Error: Invalid input. Amount must be more than $10.\n";
        return;
    }

    std::string accountID = generateAccountID();
    accounts.emplace_back(name, accountNumber, accountID, balance); // Store account in memory

    std::cout << "Account created successfully!\n";
}

void Bank::viewAccount(const std::string& accountID) {
    for (const auto& account : accounts) {
        if (account.getAccountID() == accountID) {
            std::cout << "Account ID: " << account.getAccountID() << "\n";
            std::cout << "Account Holder Name: " << account.getName() << "\n";
            std::cout << "Balance: $" << account.getBalance() << "\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}
