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

class Account {
private:
    std::string name;
    int accountNumber; 
    std::string accountID;
    double balance; 

public:
    // Constructor
    Account(std::string name, int accountNumber, std::string accountID, double balance)
        : name(name), accountNumber(accountNumber), accountID(accountID), balance(balance) {}

    // Getters
    std::string getName() const { return name; }
    int getAccountNumber() const { return accountNumber; }
    std::string getAccountID() const { return accountID; }
    double getBalance() const { return balance; }

    // Methods
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) { balance -= amount; }
};

// Function to generate a random account ID
std::string generateAccountID() {
    std::string accountID = "";
    for (int i = 0; i < 10; i++) {
        accountID += std::to_string(rand() % 10);
    }
    return accountID;
}

// Function to save account details to a CSV file
void saveAccountToFile(const Account &account) {
    std::string absolutePath = "C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data\\Account.csv";

    fs::path dataDir("C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data");
    if (!fs::exists(dataDir)) {
        fs::create_directory(dataDir); // Create the directory if it doesn't exist
    }

    std::ofstream file(absolutePath, std::ios::app); // Use the absolute path for the file

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open Account.csv for writing. Please check the file path and permissions.\n";
        return;
    }

    // Write account details as CSV
    file << account.getName() << ","
         << account.getAccountNumber() << ","
         << account.getAccountID() << ","
         << account.getBalance() << "\n";

    std::cout << "Account details saved successfully.\n"; // Feedback to user
}

// Function to generate a unique account number
int generateUniqueAccountNumber() {
    std::set<int> existingAccountNumbers; // Set to store existing account numbers
    std::ifstream inFile("C:\\Users\\kimho\\OneDrive\\Documents\\GitHub\\Bank-System\\data\\Account.csv");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            std::string accountNumStr;
            std::getline(ss, accountNumStr, ','); // Read account number from CSV
            existingAccountNumbers.insert(std::stoi(accountNumStr)); // Add to set
        }
        inFile.close();
    }

    int accountNumber;
    do {
        accountNumber = rand() % 1000000; // Generate a random account number (e.g., 6 digits)
    } while (existingAccountNumbers.find(accountNumber) != existingAccountNumbers.end()); // Ensure uniqueness

    return accountNumber; // Return unique account number
}

// Function to create a new account
void CreateAccount() {
    std::string name;
    double balance;

    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    // Validate name input
    if (name.empty()) {
        std::cerr << "Error: Name cannot be empty.\n";
        return;
    }

    // Generate a unique account number
    int accountNumber = generateUniqueAccountNumber();
    std::cout << "This is your account number: " << accountNumber << "\n";

    std::cout << "Enter balance: ";
    if (!(std::cin >> balance) || balance < 10) {
        std::cerr << "Error: Invalid input. Amount must be more than $10.\n";
        return;
    }

    // Generate account ID within this method
    std::string accountID = generateAccountID();
    Account account(name, accountNumber, accountID, balance);
    
    saveAccountToFile(account);
}

// Function to view account details by account ID
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

#include <filesystem> // Include the filesystem header
#include <string>     // Include the string header if dataDir is a string

namespace fs = std::filesystem; // Create an alias for std::filesystem


