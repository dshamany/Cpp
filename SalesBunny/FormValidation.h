#ifndef FORMVALIDATION_H
#define FORMVALIDATION_H

#include <iostream>
#include "CAString.h"
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

struct FormValidation
{
    static string REQ(){ return "required"; }

    struct FullName
    {
        static string getFirstName(const string fullName);
        static string getLastName(const string fullName);
        static string getMiddleName(const string fullName);
        static bool nameIsValid(const string fullName);
    };

    struct Address
    {
        static bool streetIsValid(string& streetName);
        static bool cityIsValid(string& cityName);
        static bool stateIsValid(string& stateName);
        static bool zipIsValid(string zip);
    };

    struct Phone
    {
        static bool numberIsValid(const string number);
    };

    // struct Appointment
    // {
    //     static bool appointmentIsValid(string appointment);
    // };
};

#endif // FORMVALIDATION_H
