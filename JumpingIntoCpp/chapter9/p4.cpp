#include <iostream>
#include <ctime>
using namespace std;

int n = 0;
bool win = false;

string slotMachineTokens[] = {"#", "*", "@", "$", "&", "%", "!"};

int randomizeToken(){
  return rand() % 7;
}

void spinMachine(){
  system("reset");
  string x, y, z;
  x = slotMachineTokens[randomizeToken()];
  y = slotMachineTokens[randomizeToken()];
  z = slotMachineTokens[randomizeToken()];

  if(x == y && y == z){
    cout << x << " " << y << " " << z << endl
         << "You Win!" << endl;
         win = true;
         n++;
  } else if(x == y || y == z || x == z){
    cout << x << " " << y << " " << z << endl
         << "You were close!" << endl;
         n++;
  } else {
    cout << x << " " << y << " " << z << endl
         << "You lose!" << endl;
         n++;
  }
}

int main(int argc, char* argv[]){
  srand(time(NULL));

  while(!win){
    char spin;
    cout << "Spin (y|n): ";
    cin >> spin;

    if(spin == 'n' || spin == 'N'){
      return 0;
    } else if(spin == 'y' || spin == 'Y'){
      spinMachine();
    }
  }
cout << "Tries: " << n << endl;

  return 0;
}
