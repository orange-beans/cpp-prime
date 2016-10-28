#include <iostream>

//int Fibonacci(int n);

long int Fibonacci(long int n) {
  if (n <= 1) {
    return n;
  } else {
    return Fibonacci(n-1) + Fibonacci(n-2);
  }
}

long long FibonacciFast(long long n) {
  int temp_1 = 0, temp_2 = 1, result = 0;
  for(int i = 2; i < n+1 ; i++) {
    // Calculate current
    result = temp_1 + temp_2;
    // Update temp_1 and temp_2
    temp_1 = temp_2;
    temp_2 = result;
  }
  return result;
}

int main(){
  long int n = 0;
  std::cin >> n;
  //std::cout << Fibonacci(n);
  std::cout << FibonacciFast(n);
  return 0;
}
