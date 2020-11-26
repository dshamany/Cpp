#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {

    // Use hash tables to filter out duplicates

    // define a set of items that we want to reduce duplicates
    std::vector<string> v1{"apple", "pear", "orange", "banana", "apple",
                           "orange","pear", "apple", "banana", "orange",
                           "apple", "kiwi"};

    // create a set from resulting keys in the hash table
    set<string> result;
    for (auto& item : v1){
        result.emplace(item);
    }

    for (auto& item : result){
        cout << item << " ";
    }
    cout << endl;

    cout << result.size() << endl;
    return 0;
}
