#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[]) {
    std::vector<int> v{12,34,45,56,67,78,89,90,100,345,125,246};

    auto result = std::accumulate(begin(v), end(v), 0, [](int total, int item){
        return total + item;
    });

    std::cout << result << std::endl;

    std::vector<int> vout{};
    std::copy_if(begin(v), end(v), back_inserter(vout), [](const int& item){
        return item % 2 == 0;
    });

    for (auto& i : vout)
        cout << i << " ";
    cout << endl;
    return 0;
}
