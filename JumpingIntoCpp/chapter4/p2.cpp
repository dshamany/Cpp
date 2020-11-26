#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  int x;
  cout << "Enter passnumber (1 or 0): ";
  cin >> x;

  (x == 1 && !(x > 1 && x < 1)) ? cout << "Logged In." << endl : cout << "Login Failed." << endl;

  return 0;
}
