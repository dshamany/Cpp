#include "FormValidation.h"
using namespace std;

void print(string val)
{
    cout << val << "\n";
}

int main(int argc, char* argv[])
{
    string input;
    // cout << "Enter State (2 Letters): ";
    getline(cin, input);

    // cout << "Phone Number is "
    //      << (FormValidation::Phone::numberIsValid(input) ? "valid" : "invalid")
    //      << endl;

    vector<string> elem = CAString::split(input, ' ');

    // copy(begin(names), end(names), std::ostream_iterator<string>(cout, ", "));

    // std::cout << "First: "
    //           << FormValidation::FullName::getFirstName(input)
    //           << "\nLast: "
    //           << FormValidation::FullName::getLastName(input)
    //           << "\nMiddle: "
    //           << FormValidation::FullName::getMiddleName(input)
    //           << "\nIs Valid: "
    //           << (FormValidation::FullName::nameIsValid(input) ? "Yes" : "No")
    //           << endl;

    // string REQ = FormValidation::REQ();
    // cout << "State is "
    //      << (FormValidation::Address::stateIsValid(input) ? "valid" : "invalid")
    //      << " and " << REQ
    //      << endl;

    // for_each(begin(names), end(names), CAString::proper);



    for_each(begin(elem), end(elem), print);
    bool isValid = FormValidation::Address::streetIsValid(input);
    cout << "Street Address is " << (isValid ? "valid" : "invalid");
    cout << endl;


    return 0;
}
