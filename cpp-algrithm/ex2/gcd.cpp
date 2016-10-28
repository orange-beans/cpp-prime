#include <iostream>

long long EuclidGCD(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return EuclidGCD(b, a % b);
  }
}

int main(){
  long long a = 0, b = 0;
  std::cin >> a;
  std::cin >> b;
  //std::cout << Fibonacci(n);
  std::cout << EuclidGCD(a, b);
  return 0;
}
