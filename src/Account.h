#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
    private:
        std::string name;            
        int accountNumber;           
        std::string accountID;       
        double balance;              

    public:
        // Constructor
        Account(std::string name, int accountNumber, std::string accountID, double balance);

        // Getters
        std::string getName() const;
        int getAccountNumber() const;
        std::string getAccountID() const;
        double getBalance() const;

        // Setters
        void setName(std::string name);
        void setAccountNumber(int accountNumber);
        void setAccountID(std::string accountID);
        void setBalance(double balance);

        // Methods
        void deposit(double amount);
        void withdraw(double amount);
};

#endif // ACCOUNT_H
