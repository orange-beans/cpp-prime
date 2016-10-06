#include <iostream>

int main() {
  int sum = 0, val, initVal = 50, lastVal = 100;
  std::cout << "Enter start and end value:" << std::endl;
  std::cin >> initVal >> lastVal;
  val = initVal;
  while(val <= lastVal) {
    sum += val;
    ++val;
  }
  std::cout << "Sum of " << initVal <<" to " << lastVal << " is "
    << sum << std::endl;
  return 0;
}
