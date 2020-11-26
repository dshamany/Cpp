#include <iostream>
#include <map>
using namespace std;

template <typename E>
struct List {
    List(){}
    ~List(){}
    List<E>* next;
    E data;
};

int main(int argc, char* argv[]){

  map<string, int> cCode;

  cCode = {
    {"Sweden", 46}, 
    {"USA", 1}
  };

  List<string> *a = new List<string>;
  List<string> *b = new List<string>;
  a->data = "A Data";
  a->next = b;
  b->data = "B Data";
  b->next = a;
  cout << a->data << endl
       << a->next->data << endl;

  cCode.insert(make_pair("SomeCountry", 17));

  for (auto it = cCode.begin(); it != cCode.end(); ++it) {
    std::cout << it->first << ", " << it->second << endl;
  }

  return 0;
}
