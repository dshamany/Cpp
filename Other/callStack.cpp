#include <iostream>

void countdown(int num){
  if (num == 0){
    printf("Done!\n");
  } else {
    printf("%d\n", num);
    countdown(num - 1);
  }
}

int power(int n, int p_num){
  if (p_num == 0){
    return 1;
  }
  return n * power(n, p_num-1);
}

int factorial(int n){
  if (n == 0){
    return 1;
  }
  return n * factorial(n-1);
}

int main(int argc, char const *argv[]) {

  // countdown(5);
  auto n = power(5, 5);
  auto m = factorial(5);
  std::cout << n << "\t" << m << std::endl;

  return 0;
}
