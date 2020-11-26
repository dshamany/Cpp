#include <iostream>
using namespace std;

int myArray[] = {32, 56, 97, 2, 53, 5, 44};
char myOtherArray[] = {'V','D','A','E','J','P','S'};

void printArray(int *array){
  int SIZE = sizeof(array);
  for (int i = 0; i < SIZE - 1; ++i){
    cout << array[i] << " | ";
  }
  cout << endl;
}
void printArray(char *array){
  int SIZE = sizeof(array) - 1;
  for (int i = 0; i < SIZE; ++i){
    cout << array[i] << " | ";
  }
  cout << endl;
}

void swap(int &a, int &b){
  a ^= b;
  b ^= a;
  a ^= b;
}



void insertionSort(int *array){
  int SIZE = sizeof(array)/sizeof(int);
  int cur, prev;
  for(int i = 1; i < SIZE; ++i){
    cur = array[i];
    prev = i - 1;

    while(prev >= 0 && array[prev] > cur){
      array[prev + 1] = array[prev];
      prev--;
      array[prev + 1] = cur;
    }
  }
}

int main(int argc, char* argv[]){

printArray(myArray);
insertionSort(myArray);
printArray(myArray);
//
//printArray(myOtherArray);
// insertionSort(myOtherArray);
//printArray(myOtherArray);

  return 0;
}
