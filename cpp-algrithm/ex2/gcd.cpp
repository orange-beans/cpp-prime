#include <iostream>
#include <time.h>

// Greatest Common Divisor
long long EuclidGCD(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return EuclidGCD(b, a % b);
  }
}

// Least Common Multiple
// 1. Find the GCD of A and B
// 2. A*B/GCD
long long LCM(long long a, long long b) {
  long long gcd = EuclidGCD(a, b);
  return a*b/gcd;
}


int main(){
  long long a = 0, b = 0;
  std::cin >> a;
  std::cin >> b;
  clock_t tStart = clock();
  // Greatest Common Divisor
  //std::cout << EuclidGCD(a, b) << std::endl;
  // Least Common Multiple
  std::cout << LCM(a, b) << std::endl;
  std::cout << "Time taken:\n" << (double)(clock() - tStart)/CLOCKS_PER_SEC << " s" << std::endl;
  return 0;
}
