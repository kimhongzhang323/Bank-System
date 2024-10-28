#include "Bank.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    Bank bank;

    while (true) {
        std::cout << "\nWelcome to the Bank System!\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. View Account\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.CreateAccount();
                break;
            case 2: {
                std::string accountID;
                std::cout << "Enter account ID to view: ";
                std::cin >> accountID;
                bank.viewAccount(accountID);
                break;
            }
            case 3:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
