#include <iostream>

int main(int argc, char const *argv[])
{
    char c;
    int ascii_value;
    while (true)
    {
        c = getchar();
        ascii_value = c;
        if (ascii_value == 27)
        {
            break;
        }
        (ascii_value != 10) && std::cout << c << " = " << ascii_value << '\n';
    }
    return 0;
}
