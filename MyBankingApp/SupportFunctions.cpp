#include "SupportHeader.h"

// Modifies the actual string it takes as an input.
std::string capitalizeFirstLetterInWord(string &str){
    // Make strings lower case, in case they are all uppercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i = 0; i < str.length(); ++i){
        // The first letter in a string + all letters after a space
        // should be uppercase
        if (str[i] == str[0] || str[i-1] == ' '){
            str[i] = toupper(str[i]);
        }
    }
    return str;
}
