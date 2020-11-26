#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char * argv[]){
  int numberOfIterations = 0;

  if (argc == 1){
  numberOfIterations = 10;
  } else if (argc > 1) {
    numberOfIterations = atoi(argv[1]);
  }

  vector<long long> sequence;
  long long n = 0;
  for(int i = 0; i < numberOfIterations; i++){
    if (n <= 1){
      sequence.push_back(n);
      n++;
    } else {
      sequence.push_back(sequence[i-1] + sequence[i-2]);
    }

  }

  system("reset");
  for (int j = 0; j < sequence.size(); j++){
  j+1 < 10 ? cout << j+1 << ": " << setw(25) << sequence[j] << endl : cout << j+1 << ": " << setw(24) << sequence[j] << endl;
  }

  return 0;
}
