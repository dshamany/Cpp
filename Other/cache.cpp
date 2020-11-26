#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

void printAll(const std::deque<int>& v){
    for (auto& i : v)
        cout << i << " ";
    cout << endl;
}

void process(int elem, deque<int>& sequence){
    if (elem == sequence[0])
        return;
    for (int i = 0; i < 5; ++i){
        if (elem == sequence[i]){
            while(i > 0){
                std::swap(sequence[i], sequence[i - 1]);
                --i;
            }
            return;
        }
    }

    sequence.pop_back();
    sequence.push_front(elem);
}

int main(int argc, char const *argv[]) {
    deque<int> cache{-1,-1,-1,-1,-1};
    int input = 0;
    while (true){
        cin >> input;
        if (input < 0) return 0;
        process(input, cache);
        printAll(cache);
    }

    return 0;
}
