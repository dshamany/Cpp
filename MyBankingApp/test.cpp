#include "SupportHeader.h"
using namespace std;

int menu();
void createCustomer();
void selectCustomer();

int main(){
    srand( time(NULL) );
    menu();

}
// menu to select options
int menu(){
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
        return 0;
        break;
    case '1':
        createCustomer();
        menu();
        break;
    case '2':
        selectCustomer();
        menu();
        break;
    }
    return 0;
}

// Create New Customer
void createCustomer(){
    Customer *c = new Customer;
    c->addAccount();
    c->description();
    CustomerList.push_back(*c);
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
    cout << "--------------------------------------------------"
         << endl
         << "Selected Customer: "
         << CustomerList[CustomerCount].returnCustomerName()
         << endl
         << "--------------------------------------------------"
         << endl;

    CustomerList[CustomerCount].selectAccount();
}
