#ifndef CASTRING_H
#define CASTRING_H

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct CAString
{
    static vector<string> split(const string text, char delimiter);
    static void upperCase(string& text);
    static void lowerCase(string& text);
    static void properCase(string& text);
};

#endif // CASTRING_H
