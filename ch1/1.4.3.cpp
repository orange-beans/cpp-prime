// Reading unknown numbers of inputs
#include <iostream>

int main() {
  int sum = 0, val = 0;

  std::cout << "please enter some numbers: " << std::endl;
  while(std::cin >> val) {
    sum += val;
  }
  std::cout << "Sum is " << sum << std::endl;
  return 0;
}
