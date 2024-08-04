#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    string password;
public:
    void create_account();
    void show_account() const;
};


void account::create_account()
{
    cout << "Enter the Account No. : ";
    cin >> acno;
    cout << "Please Enter the Name of the Account holder Here : ";
    cin.ignore(); // To ignore newline character left in the buffer
    cin.getline(name, 50);
    cout << "Please enter your password : ";
    cin >> password;
    cout << "Reenter your password : ";
    string reentered_password;
    cin >> reentered_password;
    cout << "Enter The Initial amount : ";
    cin >> deposit;

    if (password != reentered_password) {
        cout << "Password does not match" << endl;
    } else {
        cout << "Password Matched" << endl;
        cout << "Account Created..";
    }
}

void account::show_account() const
{
    cout << "Account No. : " << acno;
    cout << "Account Holder Name : " << name;
    cout << "Balance amount : " << deposit;
}

void menu()
{
    int choice;
    cout << "==========================" << endl;
    cout << "BANK MANAGEMENT SYSTEM" << endl;
    cout << "==========================" << endl;
    cout << "HAVE ACCOUNT PRESS 1 " << endl;
    cout << "DON'T HAVE ACCOUNT PRESS 2 " << endl;
    cout << "PRESS 3 TO EXIT" << endl;
    cout << "ENTER YOUR CHOICE : ";

    if (cin >> choice) {
        if (choice == 1) {
            int acno;
            string password;
            cout << "ENTER YOUR ACCOUNT NUMBER : ";
            cin >> acno;
            cout << "ENTER YOUR PASSWORD : ";
            cin >> password;
            if (acno == 1234 && password == "1234") {
                cout << "1. CREATE ACCOUNT" << endl;
                cout << "2. DEPOSIT" << endl;
                cout << "3. WITHDRAW" << endl;
                cout << "4. BALANCE ENQUIRY" << endl;
                cout << "5. ALL ACCOUNT HOLDER LIST" << endl;
                cout << "6. EXIT" << endl;
                cout << "SELECT YOUR OPTION (1-6) : ";
                // Code to handle further options
            } else {
                cout << "INVALID ACCOUNT NUMBER OR PASSWORD" << endl;
            }
        } else if (choice == 2) {
            cout << "1. CREATE ACCOUNT" << endl;
            cout << "2. EXIT" << endl;
            int sub_choice;
            cin >> sub_choice;
            if (sub_choice == 1) {
                account acc;
                acc.create_account();
            } else if (sub_choice == 2) {
                cout << "THANK YOU FOR USING BANK MANAGEMENT SYSTEM" << endl;
            }
        } else if (choice == 3) {
            cout << "THANK YOU FOR USING BANK MANAGEMENT SYSTEM" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
