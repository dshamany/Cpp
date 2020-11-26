#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    int data[3] = {1, 2, 3};
    const std::array<int, 3> d_array = std::to_array(data);

    const auto str = std::to_array("Hello, World");
    for (auto &c : str)
    {
        std::cout << c << " ";
    }
    std::cout << "\n";
    return 0;
}
