#include "SupportHeader.h"
using namespace std;

//–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// Function Declarations
int menu();
void createCustomer();
void confirm(Customer);
void selectCustomer();

int main(){
    srand( time(NULL) );
    menu();
}
// menu to select options
int menu(){
    system("reset");
    char c;
    cout << "MENU ---------------------------------------------"
    << endl
    << "[0] Exit"                                   << endl
    << "[1] New Customer"                           << endl
    << "[2] Login"                                  << endl
    << "--------------------------------------------------"
    << endl
    << "> ";
    cin >> c;
    switch(c){
        case '0':
            exit(0);
            break;
        case '1':
            createCustomer();
            break;
        case '2':
            selectCustomer();
            break;
        default:
            cerr << "Invalid! Try Again." << endl;
            break;
    }
    menu();
    return 0;
}

// Create New Customer
void createCustomer(){
    Customer *c = new Customer;
    c->addAccount();
    c->description();
    confirm(*c);
}

// Confirm creation of account
void confirm(Customer C){
    cout << "Adding Customer to Customer List."
    << endl;
    cout << "Confirm (Y/N) > ";
    char confirmation;
    cin >> confirmation;
    switch(confirmation){
        case 'y':
        case 'Y':
            CustomerList.push_back(C);
            break;
        case 'n':
        case 'N':
            menu();
            break;
        default:
            cerr << "Invalid Input." << endl;
            confirm(C);
    }
}

// Select a Customer to access or modify
void selectCustomer(){
    int CID;
    if(CustomerList.size() < 1){
        cout << "Customer List is Empty." << endl
        << "--------------------------------------------------"
        << endl;
        menu();
    }
    cout << "SELECT CUSTOMER ----------------------------------"
    << endl
    << "Enter Customer ID ('0' to Exit): ";
    cin >> CID;
    
    for(int i = 0; i < CustomerList.size(); ++i){
        if(CustomerList[i].checkCustomerID(CID)){
            break;
        }
        menu();
    }
    system("reset");
    cout << "--------------------------------------------------"
    << endl
    << "Selected Customer: "
    << CustomerList[CustomerCount].returnCustomerName()
    << endl
    << "--------------------------------------------------"
    << endl;
    
    CustomerList[CustomerCount].customerAccountMenu();
}
