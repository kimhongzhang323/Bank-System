/**
 * @file Account.h
 * @brief Header file for the Account class representing a bank account.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

/**
 * @class Account
 * @brief Represents a bank account with the ability to store basic account information and perform deposit and withdrawal operations.
 */
class Account {
    private:
        std::string name;            ///< The name of the account holder.
        int accountNumber;           ///< A unique integer representing the account number.
        std::string accountID;       ///< A unique string identifier for the account.
        double balance;              ///< The current balance of the account.

    public:
        /**
         * @brief Constructor to initialize an Account object with given details.
         * 
         * @param name The name of the account holder.
         * @param accountNumber The unique account number.
         * @param accountID The unique account identifier.
         * @param balance The initial balance of the account.
         */
        Account(std::string name, int accountNumber, std::string accountID, double balance);

        // Getters

        /**
         * @brief Gets the name of the account holder.
         * @return The name of the account holder.
         */
        std::string getName() const;

        /**
         * @brief Gets the account number.
         * @return The account number.
         */
        int getAccountNumber() const;

        /**
         * @brief Gets the account ID.
         * @return The account ID.
         */
        std::string getAccountID() const;

        /**
         * @brief Gets the current balance of the account.
         * @return The account balance.
         */
        double getBalance() const;

        // Setters

        /**
         * @brief Sets the name of the account holder.
         * @param name The new name of the account holder.
         */
        void setName(std::string name);

        /**
         * @brief Sets the account number.
         * @param accountNumber The new account number.
         */
        void setAccountNumber(int accountNumber);

        /**
         * @brief Sets the account ID.
         * @param accountID The new account ID.
         */
        void setAccountID(std::string accountID);

        /**
         * @brief Sets the account balance.
         * @param balance The new balance of the account.
         */
        void setBalance(double balance);

        // Methods

        /**
         * @brief Deposits an amount into the account balance.
         * 
         * @param amount The amount to deposit. Must be positive.
         * 
         * Prints an error message if the amount is not positive.
         */
        void deposit(double amount);

        /**
         * @brief Withdraws an amount from the account balance.
         * 
         * @param amount The amount to withdraw. Must be positive and not exceed the current balance.
         * 
         * Prints an error message if the amount is invalid (negative or exceeds balance).
         */
        void withdraw(double amount);
};

#endif // ACCOUNT_H
