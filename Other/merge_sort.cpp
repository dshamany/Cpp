#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void printVector(std::vector<int> v){
  cout << "[ ";
  for (auto i : v){
    cout << i;
    if (i != v[v.size() - 1]){ cout << ", "; }
  }
  cout << " ]";
}

void mergeSort(std::vector<int>& vec){
    if (vec.size() > 1){
        int mid   = vec.size() / 2;
        vector<int> left(begin(vec), begin(vec) + mid);
        vector<int> right(begin(vec) + mid, end(vec));

        // TODO: Recursively break down arrays
        mergeSort(left);
        mergeSort(right);

        // TODO: now perform merging
        auto i = 0; // left index
        auto j = 0; // right index
        auto k = 0; // index into merged array

        // TODO: while both arrays have content
        while (i < left.size() and j < right.size()){
            if (left[i] < right[j]){
                vec[k] = left[i];
                i++;
            } else {
                vec[k] = right[j];
                j++;
            }
            k++;
        }

        // TODO: if the left array still has content, add them
        while (i < left.size()){
            vec[k] = left[i];
            i++;
            k++;
        }

        // TODO: if the right array still has content, add them
        while (j < right.size()){
            vec[k] = right[j];
            j++;
            k++;
        }
    }
}

int main(int argc, char const *argv[]) {
    std::vector<int> v1{ 109, 654, 246, 16, 354, 12, 25, 99, 0 };
    cout << "UNSORTED:\t";
    printVector(v1);
    cout << endl;
    mergeSort(v1);
    cout << "SORTED:\t\t";
    printVector(v1);
    cout << endl;
    return 0;
}
