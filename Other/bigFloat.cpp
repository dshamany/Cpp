#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

class BigNum
{
public:
    explicit BigNum(const std::string &strNum)
        : _strNum(strNum) {}
    std::string value()
    {
        return _strNum;
    }
    void value(const std::string &str)
    {
        _strNum = str;
    }
    // BigNum operator+(BigNum &other)
    // {
    //     auto aligned = alignNumbers(this->value(), other.value());
    //     auto s1 = std::get<0>(aligned);
    //     auto s2 = std::get<1>(aligned);
    //     return BigNum(add(s1, s2));
    // }
    friend std::ostream &operator<<(std::ostream &os, BigNum &bigNum)
    {
        os << bigNum.value();
        return os;
    }
    BigNum operator+(BigNum &other)
    {
        auto aligned = alignStrNum(other.value(), this->value());
        return BigNum(add(std::get<0>(aligned), std::get<1>(aligned)));
    }

private:
    std::tuple<std::string, std::string> alignStrNum(std::string str1, std::string str2)
    {
        int d1 = str1.find('.');
        int d2 = str2.find('.');

        int diff = 0; // calculate difference

        if (d1 < d2)
        {
            diff = d2 - d1;
            for (int i = 0; i < diff; i++)
            {
                str1 = "0" + str1;
            }
        }
        else if (d2 < d1)
        {
            diff = d1 - d2;
            for (int i = 0; i < diff; i++)
            {
                str2 = "0" + str2;
            }
        }

        if (str1.size() < str2.size())
        {
            diff = str2.size() - str1.size();
            for (int i = 0; i < diff; i++)
            {
                str1.push_back('0');
            }
        }
        else if (str2.size() < str1.size())
        {
            diff = str1.size() - str2.size();
            for (int i = 0; i < diff; i++)
            {
                str2.push_back('0');
            }
        }

        return std::make_tuple(str1, str2);
    }
    std::string add(const std::string &str1, const std::string &str2)
    {
        std::string result = "";
        int tmp = 0;
        int residual = 0;

        for (int i = str1.size() - 1; i >= 0; i--)
        {
            // handle dot
            if (str1[i] == '.' && str2[i] == '.')
            {
                result += ".";
                continue;
            }

            // calculate sum
            tmp = int(str1[i] - '0') + int(str2[i] - '0') + residual;
            residual = 0;
            if (tmp > 9)
            {
                residual = (tmp / 10);
                tmp -= (residual * 10);
            }
            result += std::to_string(tmp);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
    std::string _strNum;
};

int main(int argc, char const *argv[])
{

    auto a = BigNum("123456789.123456789");
    auto b = BigNum("123456789.123456789");
    //               345979.6913221111333331104345
    auto c = a + b;

    std::cout << a.value() << '\n'
              << "+\n"
              << b.value() << '\n'
              << "---------------------\n"
              << c << '\n';

    return 0;
}