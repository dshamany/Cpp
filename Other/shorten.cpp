#include <iostream>
#include <string>

std::string shorten(const std::string &str)
{
    std::string res = "";
    char last = ' ';
    int count = 1;

    for (auto &s : str)
    {
        char n = std::toupper(s);
        if (n == last)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                res += std::to_string(count);
            }
            res += n;
            count = 1;
            last = n;
        }
    }

    if (count)
    {
        res += std::to_string(count);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    auto str = [&]() -> std::string {
        std::string _str = "";
        for (auto n = 1; n < argc; n++)
        {
            _str += argv[n];
        }
        return _str;
    };
    std::cout << shorten(str()) << '\n';
    return 0;
}
