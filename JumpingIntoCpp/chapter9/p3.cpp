#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
  srand(time(NULL));
  int n;
  int t = 0;

  int r = rand() % (100 - 1) + 1;

  while(n != r){
    n = rand() % (100 - 1) + 1;
    if(n > r){
      cout << n << " is too high." << endl;
    } else if (n < r){
      cout << n << " is too low." << endl;
    } else if (n == r){
      cout << "Your guess was correct." << endl
           << "It took you " << t << " guesses." << endl;
    }
    t++;
  }

  return 0;
}
