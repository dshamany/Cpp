#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
  srand(time(NULL));
  int n;

  int r = rand() % (100 - 1) + 1;

  while(n != r){
    cout << "Guess the number: ";
    cin >> n;
    if(n > r){
      cout << n << " is too high." << endl;
    } else if (n < r){
      cout << n << " is too low." << endl;
    } else if (n == r){
      cout << "Your guess was correct." << endl;
    }
  }

  return 0;
}
