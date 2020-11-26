#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_sorted(vector<int> items){
    int index = 0;
    while (index < (items.size() - 1)){
        if (items[index] > items[index + 1])
            return false;

        index++;
    }

    return true;
}

int binary_search(int item, vector<int> items){
    int lower = 0;
    int upper = items.size() - 1;

    while (lower <= upper){
        int mid = floor((lower + upper) / 2);

        if (items[mid] == item){
            return mid;
        }

        if (item > items[mid]){
            lower = mid + 1;
        } else {
            upper = mid - 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    vector<int> v1{6, 8, 19, 20, 23, 41, 49, 53, 56, 87};
    // cout << "Select a number: ";
    // int n;
    // cin >> n;

    if (is_sorted(v1)){
        // inser "n" instead of 56 for proper use
        cout << binary_search(56, v1) << endl;
    } else {
        cout << "List not sorted" << endl;
    }
    return 0;
}
