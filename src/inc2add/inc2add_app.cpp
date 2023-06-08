#include <iostream>

//  build && ./build/inc2add_app 999999990

uint fibo(uint num) {
  uint a = 1, b = 1, result = 1;
  if (num < 2) {
    return 1;
  }
  for (int i = 2; i <= num; i++) {
    a = b;
    b = result;
    result = a + b;
  }
  return result;
}

uint brute_calc(uint num) {
  uint result = 0;
  while (num > 0) {
    result += 1;

    num--;
  }
  return result;
}

uint dummy_ops(uint num) {
  num += 1;
  num++;
  num--;
  return num;
}

int main(int argc, char **argv) {
  uint num = atoi(argv[1]);
  // std::cout << "Fibo for num: " << num << std::endl;
  // std::cout << "Result: " << fibo(num) << std::endl;
  // std::cout << "Brute calc for: " << num << ", result= "std::cout <<
  // brute_calc(num) << std::endl;
  std::cout << dummy_ops(num) << std::endl;
  return 0;
}
