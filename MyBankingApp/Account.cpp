#pragma once
#include "SupportHeader.h"
using namespace std;

class Checking;
class Saving;

class Account{
    public:
        Account(){
            char c;
            cout << "CREATING ACCOUNT ---------------------------------" << endl
                 << "Checking or Saving (C/S)?: ";
            cin >> c;
            switch(c){
            case 'c':
            case 'C':
                type = "Checking";
                break;
            case 's':
            case 'S':
                type = "Saving";
                break;
            }
            accountNumber   = rand() % 1000000000;
            balance         = deposit();
        }
        Account createAccount();
        bool checkAccountNumber(int);
        double deposit();
        double withdraw();
        string getBalance();
        string description();
    protected:
        string   type;
        int     accountNumber;
        double  balance;
        bool interestAccount = false;
};

class Checking : public Account{
    public:
        Checking(){
            cout << "Creating Checking Account..." << endl;
            type            = "Checking";
            accountNumber   = rand() % 1000000000;
            balance         = 0;
            deposit();
        }
};

class Saving : public Account{
    public:
        Saving(){
            cout << "Creating Saving Account..." << endl;
            type            = "Saving";
            accountNumber   = rand() % 1000000000;
            balance         = deposit();
        }
};

//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool Account::checkAccountNumber(int n){
    if(n == this->accountNumber){
        return true;
    } else {
        return false;
    }
    cout << "--------------------------------------------------" << endl;
}

double Account::deposit(){
    double amt;
    cout << "Deposit Amount: ";
    cin >> amt;
    return balance += amt;
}

double Account::withdraw(){
    double amt;
    cout << "Withdraw Amount: ";
    cin >> amt;
    return balance -= amt;
}

string Account::getBalance(){
    // convert balance to string
    ostringstream convert;
    string bal;
    convert << balance;
    bal = convert.str();

    return "Balance: \t" + bal;
}

string Account::description(){
    string acctNum, bal;
    ostringstream convert1;
    ostringstream convert2;

    //convert accountNumber to string
    convert1 << accountNumber;
    acctNum = convert1.str();

    // convert balance to string
    convert2 << balance;
    bal = convert2.str();

    return "Type: \t\t" + type + "\n"
    + "Account Number: " + acctNum + "\n"
    + "Balance: \t" + bal
    +    "\n--------------------------------------------------";
}
