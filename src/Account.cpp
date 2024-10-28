#include "Account.h"
#include <iostream>

// Constructor
Account::Account(std::string name, int accountNumber, std::string accountID, double balance) 
    : name(name), accountNumber(accountNumber), accountID(accountID), balance(balance) {}

// Getters
std::string Account::getName() const {
    return name;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountID() const {
    return accountID;
}

double Account::getBalance() const {
    return balance;
}

// Setters
void Account::setName(std::string name) {
    this->name = name;
}

void Account::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

void Account::setAccountID(std::string accountID) {
    this->accountID = accountID;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

// Methods to deposit and withdraw money
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Deposit amount must be positive.\n";
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Invalid withdrawal amount.\n";
    }
}
