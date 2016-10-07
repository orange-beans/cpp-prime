// Reading unknown numbers of inputs
// Notes:
// 1. on Windows systems we enter an end-of-file by typing
//    ctrl-z; on Linux or Mac, it is ctrl-d;

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
