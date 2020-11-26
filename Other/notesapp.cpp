#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cout;
using std::fstream;
using std::string;

int main(int argc, char const *argv[])
{
    string filename = "text.txt";

    fstream fs(filename, fs.trunc | fs.in | fs.out);

    if (!fs.is_open())
    {
        cerr << "File could not open\n";
    }
    else
    {
        // write to file
        for (int i = 1; i < argc; i++)
        {
            fs << argv[i] << '\n';
        }
    }

    char *read_str;

    fs.close();

    return 0;
}
