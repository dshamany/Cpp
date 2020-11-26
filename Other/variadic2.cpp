#include <iostream>

// Base Case
template <typename T>
T summer(T amount){
    return amount;
}

// Recursive Case
template <typename T, typename... Ts>
double summer(T amount, Ts... args){
    return amount + summer(args ...);
}

int main(int argc, char const *argv[]) {
    auto x = summer(2.0, 3.3, 4.4, 5.5, 5);
    std::cout << "summer(2.0, 3.3, 4.4, 5.5, 5) = " << x << std::endl;
    return 0;
}
