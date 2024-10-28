#include "Bank.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Main entry point for the bank system application.
 * 
 * This program provides a basic console interface for a bank system,
 * allowing users to create accounts and view account details. The
 * main loop displays a menu and takes user input to perform actions
 * on the bank system.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator for account ID generation.
    int choice;
    std::string accountID;

    // Main program loop to display menu options and perform actions based on user input.
    do {
        std::cout << "Bank System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. View Account\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                CreateAccount();  // Calls function to create a new account.
                break;
            case 2:
                std::cout << "Enter Account ID to view: ";
                std::cin >> accountID;
                viewAccount(accountID);  // Calls function to view account details based on account ID.
                break;
            case 0:
                std::cout << "Exiting...\n";  // Exits the program.
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";  // Handles invalid menu choices.
        }
    } while (choice != 0);

    return 0;
}
