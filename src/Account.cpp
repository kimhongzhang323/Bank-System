/**
 * @file Account.cpp
 * @brief Implementation of the Account class representing a bank account.
 */

#include "Account.h"
#include <iostream>

/**
 * @class Account
 * @brief Represents a bank account with basic account information and operations.
 */

/**
 * @brief Constructor to initialize an Account object.
 * 
 * @param name The name of the account holder.
 * @param accountNumber A unique account number.
 * @param accountID A unique identifier for the account.
 * @param balance The initial balance of the account.
 */
Account::Account(std::string name, int accountNumber, std::string accountID, double balance) 
    : name(name), accountNumber(accountNumber), accountID(accountID), balance(balance) {}

// Getters

/**
 * @brief Gets the name of the account holder.
 * 
 * @return The name of the account holder.
 */
std::string Account::getName() const {
    return name;
}

/**
 * @brief Gets the account number.
 * 
 * @return The account number.
 */
int Account::getAccountNumber() const {
    return accountNumber;
}

/**
 * @brief Gets the account ID.
 * 
 * @return The account ID.
 */
std::string Account::getAccountID() const {
    return accountID;
}

/**
 * @brief Gets the current balance of the account.
 * 
 * @return The account balance.
 */
double Account::getBalance() const {
    return balance;
}

// Setters

/**
 * @brief Sets the name of the account holder.
 * 
 * @param name The new name of the account holder.
 */
void Account::setName(std::string name) {
    this->name = name;
}

/**
 * @brief Sets the account number.
 * 
 * @param accountNumber The new account number.
 */
void Account::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

/**
 * @brief Sets the account ID.
 * 
 * @param accountID The new account ID.
 */
void Account::setAccountID(std::string accountID) {
    this->accountID = accountID;
}

/**
 * @brief Sets the account balance.
 * 
 * @param balance The new balance of the account.
 */
void Account::setBalance(double balance) {
    this->balance = balance;
}

// Methods

/**
 * @brief Deposits an amount into the account balance.
 * 
 * @param amount The amount to deposit. Must be positive.
 * 
 * Prints an error message if the amount is not positive.
 */
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Deposit amount must be positive.\n";
    }
}

/**
 * @brief Withdraws an amount from the account balance.
 * 
 * @param amount The amount to withdraw. Must be positive and not exceed the current balance.
 * 
 * Prints an error message if the amount is invalid (negative or exceeds balance).
 */
void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Invalid withdrawal amount.\n";
    }
}
