#include "FormValidation.h"
using namespace std;

string FormValidation::FullName::getFirstName(const string fullName)
{
    vector<string> names = CAString::split(fullName, ' ');
    return names[0];
}

string FormValidation::FullName::getLastName(const string fullName)
{
    vector<string> names = CAString::split(fullName, ' ');
    return names[names.size() - 1];
}

string FormValidation::FullName::getMiddleName(const string fullName)
{
    string result;
    auto names = CAString::split(fullName, ' ');

    for (int i = 1; i < names.size() - 1; ++i)
    {
        result += names[i] + " ";
    }

    return result;
}

bool FormValidation::FullName::nameIsValid(const string fullName)
{
    return getFirstName(fullName) != getLastName(fullName);
}

bool FormValidation::Address::streetIsValid(string &streetName)
{
    for (auto i : streetName){
        if (i == '-') return false;
    }
    return true;
}

bool FormValidation::Address::cityIsValid(string &cityName)
{
    return true;
}

bool FormValidation::Address::stateIsValid(string& stateName)
{
    transform(begin(stateName), end(stateName), begin(stateName), ::toupper);
    vector<string> states = {"AL", "AK", "AZ", "AR", "CA", "CO",
                             "CT", "DC", "DE", "FL", "GA", "HI",
                             "ID", "IL", "IN", "IA", "KS", "KY",
                             "LA", "ME", "MD", "MA", "MI", "MN",
                             "MS", "MO", "MT", "NE", "NV", "NH",
                             "NJ", "NM", "NY", "NC", "ND", "OH",
                             "OK", "OR", "PA", "RI", "SC", "SD",
                             "TN", "TX", "UT", "VT", "WA", "WV",
                             "WI", "WY"};
    if (stateName.size() > 2 || stateName.size() < 2){ return false; }

    for (auto i : states){
        if (stateName == i)
            return true;
    }
    return false;
}

bool FormValidation::Address::zipIsValid(string zip)
{
    if (zip.size() > 5 || zip.size() < 5){ return false; }
    return true;
}

bool FormValidation::Phone::numberIsValid(const string number)
{
    // number is exactly 10 digits long
    if (number.size() < 10 || number.size() > 10){ return false; }

    // number only contains digits
    string::const_iterator it = begin(number);
    while ( it != end(number) && isdigit(*it)) ++it;
    return !number.empty() && it == end(number);
}
