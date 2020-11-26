#include <iostream>
#include <variant>

int main(int argc, char const *argv[])
{
    std::variant<std::string, int> data;
    data = "Dan";
    data = 77;
    switch (data.index())
    {
    case 0:
        std::cout << std::get<std::string>(data) << "\n";
        break;
    case 1:
        std::cout << std::get<int>(data) << "\n";
        break;
    }

    return 0;
}
