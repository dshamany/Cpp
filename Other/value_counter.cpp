#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
    // define a set of items that we want to reduce duplicates
    vector<string> v1{"apple", "pear", "orange", "banana", "apple", "orange",
                      "pear", "apple", "banana", "orange", "apple", "kiwi"};

    // create hashtable to hold items and increment count
    map<string, int> counter;

    // iterate over all items in v1 and increment counter
    for (string item : v1){
        counter[item]++;
    }

    for (auto& item : counter){
        cout << item.first << "\t=\t" << item.second << endl;
    }

    return 0;
}
