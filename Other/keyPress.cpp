#include <iostream>
#include <string>
#include <codecvt>
using namespace std;

int main()
{

    std::string key_press;
    int ascii_value;
    cout << "\n\t\t\tPress Any Key to Check its ASCII Value\n\n\t\t\t\tPress ESC to EXIT\n\n\n";
    while (true)
    {
        getline(cin, key_press);
        ascii_value = key_press[0];
        cout << "\t\t\tKey Pressed-> \"" << key_press << "\" Ascii Value = " << ascii_value << "\n\n";
        if (ascii_value == 27)
        {
            break;
        }
    }
    return 0;
}