#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

std::tuple<int,int, int> productof(std::vector<int> vec, int result){
    int tmp = result;
    for (auto& i : vec){
        tmp = result / i;
        for (int j = 0; j < vec.size() - 1; ++j){
            if (vec[j] == tmp){
                auto tmpResult = std::tuple<int,int, int>(i, vec[j], result);
                return tmpResult;
            }
        }
    }
    std::tuple<int,int, int> altResult(0, 0, 0);
    return altResult;
}

int main(int argc, char const *argv[]) {
    std::vector<int> vec{2,4,1,6,5,40,-1};

    auto m = productof(vec, 20);

    cout << std::get<0>(m) << " * " << get<1>(m) << " = " << get<2>(m) << endl;

    return 0;
}
