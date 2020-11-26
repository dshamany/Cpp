#include "CAString.h"

std::vector<string> CAString::split(const string text, char delimiter)
{
    vector<string> result;
    stringstream ss(text);
    string elem;
    while ( getline(ss, elem, delimiter) )
    {
        result.push_back(elem);
    }

    return result;
}

void CAString::lowerCase(string &text)
{
    transform(begin(text), end(text), begin(text), ::tolower);
}

void CAString::upperCase(string &text)
{
    transform(begin(text), end(text), begin(text), ::toupper);
}

void CAString::properCase(string &text)
{
    text[0] = toupper(text[0]);
}
