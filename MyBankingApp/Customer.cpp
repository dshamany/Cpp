#pragma once
#include "SupportHeader.h"
#include "SupportFunctions.cpp"
using namespace std;

class Customer{
    public:
        Customer(){
            system("reset");
            cout << "CREATE CUSTOMER   ----------------------------------"
                 << endl;
            customerID  = rand() % 10000000;
            firstName   = inputFirstName();
            lastName    = inputLastName();
            street      = inputStreetAddress();
            city        = inputCity();
            state       = inputState();
            zip         = inputZip();
            email       = inputEmail();
            phoneNumber = inputPhoneNumber();

            cout << "--------------------------------------------------"
                 << endl
                 << "Added to Customer List" << endl
                 << "--------------------------------------------------"
                 << endl;

        }
        string returnCustomerName(){
            return firstName + " " + lastName;
        }
        void description();
        bool checkCustomerID(int);
        void customerAccountMenu();
        void addAccount();
        int  selectAccount();
        void accessAccount(int);

        void modifyAccount();

        void changeFirstName();
        void changeLastName();
        void changeEmail();
        void changePhoneNumber();
        void changeAddress();
        void deleteCustomer();

    protected:
        //declarations
        string inputFirstName();
        string inputLastName();
        string inputStreetAddress();
        string inputCity();
        string inputState();
        string inputZip();
        bool   check(string);
        string inputEmail();
        string inputPhoneNumber();

        // private variables
        int AccountCount;
        vector<Account> AcctList;
        long    customerID;
        string  firstName;
        string  lastName;
        string  street;
        string  city;
        string  state;
        string  zip;
        string  email;
        string  phoneNumber;
        string  password;
};

string Customer::inputFirstName(){
    string fName;
    cout << "Enter First Name: ";
    getline(cin >> ws, fName);
    return capitalizeFirstLetterInWord(fName);
}

string Customer::inputLastName(){
    string lName;
    cout << "Enter Last Name: ";
    getline(cin >> ws, lName);
    return capitalizeFirstLetterInWord(lName);
}

// Input, format, and check for '@' in email address
string Customer::inputEmail(){
    string email;
    cout << "Enter Email Address: ";
    getline(cin >> ws, email);

    transform(email.begin(), email.end(), email.begin(), ::tolower);
        // Make sure an '@' is in the email address.
        for(int i = 0; i < email.length(); ++i){
            if(email[i] == '@'){
                return email;
            }
        }
    cerr << "Error! '@' is missing." << endl;
    return inputEmail();
}

// Input and format phone number.
string Customer::inputPhoneNumber(){
    string num, fStr, sStr, tStr;
    cout << "Enter Phone Number: ";
    cin >> num;
    // Check phone number length.
    if(num.length() < 10){
    cerr << "Error! phone number is too short " << endl;
    return inputPhoneNumber();
    }
    if(num.length() > 10){
    cerr << "Error! phone number is too long " << endl;
    return inputPhoneNumber();
    }
    // Slice phone number and add to return string.
    fStr = num.substr(0, 3);
    sStr = num.substr(3, 3);
    tStr = num.substr(6, 4);
    return "+1" + fStr + sStr + tStr;
}

// Displays customer information.
void Customer::description(){
    cout << "CUSTOMER OUTPUT ----------------------------------" << endl;
    cout << "Customer ID: \t" << customerID     << endl
         << "First Name: \t" << firstName       << endl
         << "Last Name: \t" << lastName         << endl
         << "Street: \t" << street              << endl
         << "\t\t" << city << ", " << state << " " << zip
         << endl
         << "Email Address: \t" << email        << endl
         << "Phone Number: \t" << phoneNumber   << endl
         << "--------------------------------------------------" << endl;
}

// Find a customer by entering CustomerID
bool Customer::checkCustomerID(int CID){
    for(int i = 0; i < CustomerList.size(); ++i){
        if (CustomerList[i].customerID == CID){
           CustomerCount = i;
           return true;
        } else {
            cerr << "No Customer Found." << endl;
        }
    }
    return false;
}

// Customer Account Menu
void Customer::customerAccountMenu(){
    cout << "[0] Logout"                    << endl
         << "[1] Customer Information"      << endl
         << "[2] Access Bank Accounts"      << endl
         << "[3] Add Bank Account"          << endl
         << "[4] Modify Customer Account"   << endl
         << "[5] Delete Customer Account"   << endl
         << "--------------------------------------------------"
         << endl
         << "> ";
    int c;
    cin >> c;
    switch(c){
    case 0:
        menu();
        break;
    case 1:
        description();
        break;
    case 2:
        selectAccount();
        break;
    case 3:
        addAccount();
        break;
    case 4:
        modifyAccount();
        break;
    case 5:
        CustomerList.erase(CustomerList.begin()
        + CustomerCount);
        menu();
        break;
    }
    customerAccountMenu();
}

// Create a new account and add it to AcctList
void Customer::addAccount(){
    Account a;
    AcctList.push_back(a);
    cout << "--------------------------------------------------"
         << endl
         << "Account Added."
         << endl
         << "--------------------------------------------------"
         << endl
         << AcctList[AccountCount].description()
         << endl;
         AccountCount++;
}

// Choose an account to access or modify
int Customer::selectAccount(){
    int acct;
    if(AcctList.size() > 0){
        for(int i = 0; i < AcctList.size(); ++i){
            cout << "ACCOUNT " << i+1
                 << " ----------------------------------------"
                 << endl
                 << CustomerList[CustomerCount].AcctList[i].description()
                 << endl;
             }
         }
         cout << "Select Account ('0' to Exit) > ";
         cin >> acct;
         if(acct == 0){
            customerAccountMenu();
        } else if(AcctList.size() < (acct-1)){
             selectAccount();
         } else if((acct-1) <= AcctList.size()){
             system("reset");
             accessAccount(acct-1);
         } else {
             cerr << "Invalid Input." << endl;
              customerAccountMenu();
         }
    return 0;
}

// Access account properties
void Customer::accessAccount(int n){
    cout << "ACCOUNT ACCESS -----------------------------------"
         << endl
         << "[0] Back"                  << endl
         << "[1] Deposit"               << endl
         << "[2] Withdraw"              << endl
         << "[3] Display Account"       << endl
         << "[4] Delete Bank Account"   << endl
         << "--------------------------------------------------"
         << endl
         << "> ";

         char c;
         cin >> c;
         switch(c){
         case '0':
             selectAccount();
             break;
         case '1':
             AcctList[n].deposit();
             accessAccount(n);
             break;
         case '2':
             AcctList[n].withdraw();
             accessAccount(n);
             break;
         case '3':
             cout << AcctList[n].getBalance() << endl
                  << "--------------------------------------------------"
                  << endl;
            accessAccount(n);
            break;
        case '4':
            AcctList.erase(AcctList.begin() + n);
            selectAccount();
            break;
        default:
            cerr << "Invalid! Try Again." << endl;
             accessAccount(n);
             break;
         }
}

//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// Make changes to Customer Account
void Customer::modifyAccount(){
    cout << "MODIFY -------------------------------------------"
         << endl
         << "[0] Back"            << endl
         << "[1] First Name"        << endl
         << "[2] Last Name"         << endl
         << "[3] Address"           << endl
         << "[4] E-Mail"            << endl
         << "[5] Phone Number"      << endl
         << "--------------------------------------------------" << endl
         << "> ";

         char c;
         cin >> c;
         switch(c){
         case '0':
             system("reset");
             break;
         case '1':
             changeFirstName();
             break;
         case '2':
             changeLastName();
             break;
         case '3':
             changeAddress();
             break;
         case '4':
             changeEmail();
             break;
         case '5':
             changePhoneNumber();
             break;
         }
}
void Customer::changeFirstName(){
    cout << "Current First Name: " << firstName << endl;
    firstName = inputFirstName();
    modifyAccount();
}
void Customer::changeLastName(){
    cout << "Current Last Name: " << lastName << endl;
    lastName = inputLastName();
    modifyAccount();
}
void Customer::changeEmail(){
    cout << "Current Email: " << email
         << endl;
    email = inputEmail();
    modifyAccount();
}
void Customer::changePhoneNumber(){
    cout << "Current Phone Number: " << phoneNumber << endl;
    phoneNumber = inputPhoneNumber();
    modifyAccount();
}
void Customer::changeAddress(){
    cout << "Current Address : " << street << endl
         << "\t\t" << city << ", " << state
         << " " << zip << endl;
    street  = inputStreetAddress();
    city    = inputCity();
    state   = inputState();
    zip     = inputZip();
    modifyAccount();
}
void Customer::deleteCustomer(){
    CustomerList.erase(CustomerList.begin() + CustomerCount);
    CustomerCount = 0;
    modifyAccount();
}

//––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// Adds address line and capitalizes names.
string Customer::inputStreetAddress(){
    string street;
    cout << "Enter Street: ";
    getline(cin >> ws, street);
    return capitalizeFirstLetterInWord(street);
}

// Adds city and capitalizes name.
string Customer::inputCity(){
    string city = " ";
    cout << "Enter City: ";
    getline(cin >> ws, city);
    return capitalizeFirstLetterInWord(city);
}

// Checks if input of state matches actual U.S. States
bool Customer::check(string c){
    for(int i = 0; i < 50; ++i){
        if(string(c) == states[i]){
            return true;
        }
    }
    return false;
}

// Input and check state validity
string Customer::inputState(){
    string in = "";
    cout << "State: ";
    cin >> in;

    // Converts to all uppercase
    transform(in.begin(), in.end(), in.begin(), ::toupper);

    // Assures that two letters (no more or less) are inputed.
    if(in.length() < 2){
        cerr << "Error! State abbreviation is too short." << endl
             << "Try Again..." << endl;
        return inputState();
    } else if(in.length() > 2){
        cerr << "Error! State abbreviation is too long." << endl
             << "Try Again..." << endl;
        return inputState();
    }

    // If State is not real, Error is printed.
    if(check(in) != true){
        cerr << "Invalid State!" << endl;
        return inputState();
    }

    return in;
}

// Assures that only 5 digits can be entered.
string Customer::inputZip(){
    string zip;
    cout << "Enter Five (5) Digit Zip: ";
    cin >> zip;

    if (zip.length() < 5 || zip.length() > 5){
        cerr << "Invalid ZipCode. " << endl;
        cout << "Try Again...";
        return inputZip();
    }
    return zip;
}
