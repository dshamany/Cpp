#include <iostream>
#include <vector>
using namespace std;

int find_max(std::vector<int> vec){
    int max = 0;

    for (auto& i : vec){
        if (i > max){
            max = i;
        }
    }
    return max;
}

int main(int argc, char const *argv[]) {
    std::vector<int> v1{6, 20, 8, 19, 56, 23, 87, 41, 49, 53};

    cout << find_max(v1) << endl;

    return 0;
}
