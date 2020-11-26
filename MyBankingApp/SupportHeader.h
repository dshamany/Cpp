#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class Account;
class Checking;
class Saving;
class Customer;
int menu();
void createCustomer();
void confirm(Customer);
void selectCustomer();

#include "Data.cpp"
#include "Account.cpp"
#include "Customer.cpp"


std::string capitalizeFirstLetterInWord(string&);
