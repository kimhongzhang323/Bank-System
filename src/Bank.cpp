#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <set>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time
#include <string>
#include <filesystem> // For filesystem operations
namespace fs = std::filesystem;

/**
 * @class Account
 * @brief Represents a bank account with basic information and operations.
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

    // Getters
    std::string getName() const;
    int getAccountNumber() const;
    std::string getAccountID() const;
    double getBalance() const;

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
};

/**
 * @brief Generates a random 10-digit account ID.
 * @return A string containing a randomly generated 10-digit account ID.
 */
std::string generateAccountID() {
    std::string accountID = "";
    for (int i = 0; i < 10; i++) {
        accountID += std::to_string(rand() % 10);
    }
    return accountID;
}

/**
 * @brief Saves the account details to a CSV file.
 * @param account The Account object containing details to save.
 */
void saveAccountToFile(const Account &account) {
    std::string absolutePath = "C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data\\Account.csv";

    // Ensure the directory exists; create if it does not.
    fs::path dataDir("C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data");
    if (!fs::exists(dataDir)) {
        fs::create_directory(dataDir);
    }

    // Open file in append mode to add account details
    std::ofstream file(absolutePath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open Account.csv for writing. Please check the file path and permissions.\n";
        return;
    }

    // Write account details to CSV
    file << account.getName() << ","
         << account.getAccountNumber() << ","
         << account.getAccountID() << ","
         << account.getBalance() << "\n";

    std::cout << "Account details saved successfully.\n";
}

/**
 * @brief Generates a unique account number that does not already exist in the data file.
 * @return A unique integer representing the account number.
 */
int generateUniqueAccountNumber() {
    std::set<int> existingAccountNumbers; // Set to store existing account numbers

    // Open CSV file and read existing account numbers
    std::ifstream inFile("C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data\\Account.csv");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            std::string accountNumStr;
            std::getline(ss, accountNumStr, ','); // Read account number from CSV
            existingAccountNumbers.insert(std::stoi(accountNumStr));
        }
        inFile.close();
    }

    int accountNumber;
    // Generate a unique account number by avoiding existing ones
    do {
        accountNumber = rand() % 1000000; // Generate a 6-digit number
    } while (existingAccountNumbers.find(accountNumber) != existingAccountNumbers.end());

    return accountNumber;
}

/**
 * @brief Prompts the user to enter account information and creates a new account.
 */
void CreateAccount() {
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
    Account account(name, accountNumber, accountID, balance);

    saveAccountToFile(account);
}

/**
 * @brief Searches for and displays account details by the given account ID.
 * @param accountID The ID of the account to view.
 */
void viewAccount(const std::string& accountID) {
    std::ifstream inFile("C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data\\Account.csv");
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open account data file.\n";
        return;
    }

    std::string line;
    bool accountFound = false;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string id, name, accountNumStr, balanceStr;
        std::getline(ss, name, ',');
        std::getline(ss, accountNumStr, ',');
        std::getline(ss, id, ',');
        std::getline(ss, balanceStr);

        if (id == accountID) {
            accountFound = true;
            std::cout << "Account ID: " << id << "\n";
            std::cout << "Account Holder Name: " << name << "\n";
            std::cout << "Balance: $" << balanceStr << "\n";
            break;
        }
    }
    inFile.close();

    if (!accountFound) {
        std::cout << "Account not found.\n";
    }
}
