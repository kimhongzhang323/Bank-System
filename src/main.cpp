// main.cpp
#include "Bank.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int choice;
    std::string accountID;

    do {
        std::cout << "Bank System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. View Account\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                CreateAccount();
                break;
            case 2:
                std::cout << "Enter Account ID to view: ";
                std::cin >> accountID;
                viewAccount(accountID);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
