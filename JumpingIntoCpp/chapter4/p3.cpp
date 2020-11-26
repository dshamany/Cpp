#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  char op;
  double n1, n2;
  cout << "Enter number followed by operator (+, -, *, /) followed by number: ";
  cin >> n1 >> op >> n2;

  switch(op){
    case '+':
    cout << n1 + n2 << endl;
    break;
    case '-':
    cout << n1 - n2 << endl;
    break;
    case '*':
    cout << n1 * n2 << endl;
    break;
    case '/':
    cout << n1 / n2 << endl;
    break;
  }

  return 0;
}
