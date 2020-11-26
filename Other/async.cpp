#include <iostream>
#include <numeric>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>

std::string pretty_print_number(const int &num)
{
    std::string str_num = std::to_string(num);

    for (auto it = str_num.rbegin(); it != str_num.rend(); ++it)
    {

        if ((str_num.rend() - it) % 3 == 1)
        {
            str_num.insert(str_num.rend() - it, 1, ',');
        }
    }

    if (str_num[str_num.size() - 1] == ',')
    {
        str_num.pop_back();
    }

    return str_num;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = std::accumulate(v.begin(), v.end(), 0);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Product: " << product << '\n';

    std::cout << "Formatted Product: " << pretty_print_number(1234567890.456) << '\n';
    return 0;
}
