#include <iostream>
#include <typeinfo>

using namespace std;

void whatType(int i){
  std::cout << "Integer" << std::endl;
}

void whatType(std::string i){
  std::cout << "String" << std::endl;
}

void whatType(char i){
  std::cout << "Character" << std::endl;
}

void whatType(bool i){
  std::cout << "Boolean" << std::endl;
}

template <typename T>
void whatType(T t){
  std::cout << "Custom" << std::endl;
}

int main(int argc, char* argv[]){

  std::string str;
  int i;
  char c;
  bool b;

  whatType(str);
  whatType(i);
  whatType(c);
  whatType(b);

  return 0;
}
