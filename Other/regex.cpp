#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main(int argc, char const *argv[])
{
    std::string s = argc > 1 ? argv[1] : "kgmv;lkdsm klmklsm klcsmdlkcdmskldmfk;lmsvlkdsmckldsmgld,.f/,gf/.b,gfn.b,gfdb/f,df123.456.7890";
    boost::regex expr("\\d{3}[.-]\\d{3}[.-]\\d{4}");
    boost::smatch result;
    if (boost::regex_search(s, result, expr))
    {
        for (auto &r : result)
        {
            std::cout << r << '\n';
        }
    }

    return 0;
}