#include <iostream>
#include <algorithm>
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

void bubbleSort(vector<int>& vec){
  for (auto i : vec){
    for (auto& j : vec){
      if (j > *(&j + 1))
        swap(j, *(&j + 1));
    }
    cout << "CURRENT STATE: ";
    printVector(vec);
    cout << endl;
  }
}


int main(int argc, char const *argv[]) {
  std::vector<int> v1{ 109, 654, 246, 16, 354, 12, 25, 99, 0 };

  cout << "UNSORTED:\t";
  printVector(v1);

  cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

  bubbleSort(v1);

  cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
  cout << "SORTED:\t\t";
  printVector(v1);
  cout << endl;

  return 0;
}
