#ifndef BANK_H
#define BANK_H

#include <string>

/**
 * @brief Creates a new account by prompting the user for input and saving the details.
 */
void CreateAccount();

/**
 * @brief Displays account details for a given account ID.
 * @param accountID The ID of the account to view.
 */
void viewAccount(const std::string& accountID);

/**
 * @class Account
 * @brief Represents a bank account with basic information and financial operations.
 */
class Account {
private:
    std::string name;            ///< Account holder's name.
    int accountNumber;           ///< Unique account number.
    std::string accountID;       ///< Unique identifier for the account.
    double balance;              ///< Current account balance.

public:
    /**
     * @brief Constructs an Account with given details.
     * @param name Name of the account holder.
     * @param accountNumber Unique account number.
     * @param accountID Unique identifier for the account.
     * @param balance Initial balance of the account.
     */
    Account(std::string name, int accountNumber, std::string accountID, double balance);

    /**
     * @brief Gets the name of the account holder.
     * @return Account holder's name.
     */
    std::string getName() const;

    /**
     * @brief Gets the unique account number.
     * @return Account number.
     */
    int getAccountNumber() const;

    /**
     * @brief Gets the unique account ID.
     * @return Account ID.
     */
    std::string getAccountID() const;

    /**
     * @brief Gets the current balance of the account.
     * @return Account balance.
     */
    double getBalance() const;

    /**
     * @brief Deposits a specified amount into the account.
     * @param amount Amount to deposit.
     */
    void deposit(double amount);

    /**
     * @brief Withdraws a specified amount from the account if funds are sufficient.
     * @param amount Amount to withdraw.
     */
    void withdraw(double amount);
};

// Function declarations

/**
 * @brief Generates a random 10-digit account ID.
 * @return A string containing a randomly generated 10-digit account ID.
 */
std::string generateAccountID();

/**
 * @brief Saves the account details to a CSV file.
 * @param account The Account object containing details to save.
 */
void saveAccountToFile(const Account &account);

/**
 * @brief Generates a unique account number that does not already exist in the data file.
 * @return A unique integer representing the account number.
 */
int generateUniqueAccountNumber();

#endif // BANK_H
