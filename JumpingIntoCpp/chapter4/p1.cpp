#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  int x, y;
  cout << "Enter age of first user: ";
  cin >> x;
  cout << "Enter age of second user: ";
  cin >> y;

  if(x > 100 && y > 100){
    cout << "Both of you are old." << endl;
  } else if (x > y){
    cout << "First user is older than the second user." << endl;
  } else if (x < y){
    cout << "Second user is older than the first user." << endl;
  } else if (x == y){
    cout << "You're both of equal age." << endl;
  }

  return 0;
}
