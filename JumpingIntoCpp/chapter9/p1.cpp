#include <iostream>
#include <ctime>
using namespace std;

int h = 0;
int t = 0;


string performCoinFlip(){
  if((rand() % 100) > 50){
    h++;
    return "Head";
  } else {
    t++;
    return "Tail";
  }
}

void performCoinFlipNTimes(int n){
  for(int i = 0; i < n; ++i){
    cout << performCoinFlip() << endl;
  }
}

int main(int argc, char* argv[]){
  srand(time(NULL));

  int n;
  cout << "Choose the number of coin flips you want to perform: ";
  cin >> n;

  if (n < 0){
    cout << "Running less than one coin flip is not possible." << endl;
    return 0;
  } else {
    performCoinFlipNTimes(n);
  }

  cout << "Heads: " << h << endl
       << "Tails: " << t << endl;

  return 0;
}
