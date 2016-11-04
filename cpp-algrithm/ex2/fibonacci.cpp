#include <iostream>
#include <time.h>
#include <vector>

//int Fibonacci(int n);

long int Fibonacci(long int n) {
  if (n <= 1) {
    return n;
  } else {
    return Fibonacci(n-1) + Fibonacci(n-2);
  }
}

// O(n^2)
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

// Last digit of a Large Fibonacci Number
long long LastDigitOfFinonacci(long long n) {
  int temp_1 = 0, temp_2 = 1, result = 0;
  for(int i = 2; i < n+1 ; i++) {
    // Calculate current
    result = (temp_1 + temp_2)%10;
    // Update temp_1 and temp_2
    temp_1 = temp_2;
    temp_2 = result;
  }
  return result;
}

// Huge Fibonacci Number modulom
// Step 1. Find the Pisano period (results will repeat)
// Step 2. Find n % period, then lookup in the period table
long long HugeFinonacciModul(long long n, long long m) {
  // Step 1:
  std::vector<long long> table;
  table.push_back(0);
  table.push_back(1);
  int i = 2, period = 0;
  //std::cout << 0 << " : " << table[0] << std::endl;
  //std::cout << 1 << " : " << table[1] << std::endl;
  while(true) {
    // Find Fibonacci Number
    table.push_back((table[i-1] + table[i-2])%m);
    //table[i] = (table[i-1] + table[i-2])%m;
    //std::cout << i << " : " << table[i] << std::endl;
    // Store after module
    if(table[i]==1 && table[i-1]==0) break;
    i++;
  }
  table.resize(i-1);
  // Step 2:
  period = table.size();
  return table[n % period];
}

// Sum of Fibonacci Numbers
// Analysis: Sum = F(n+2) - F(1) = F(n+2) - 1;
// Step 1: Find F(n+2), last digital modulom by 10;
// Step 2: return result - 1
long long SumOfFibonacci(long long n) {
  long long n_plus_2 = HugeFinonacciModul(n+2, 10);
  n_plus_2 = n_plus_2 == 0 ? 10 : n_plus_2;
  return n_plus_2 - 1;
}

// Partial Sum of Fibonacci Numbers
// Analysis: Sum = F(n+2) - F(m+1);
// Step 1: Find F(n+2) & F(m+1), last digital modulom by 10;
// Step 2: return result;
long long PartialSumOfFibonacci(long long n, long long m) {
  long long n_plus_2 = HugeFinonacciModul(n+2, 10);
  long long m_plus_1 = HugeFinonacciModul(m+1, 10);
  if (n_plus_2 < m_plus_1) n_plus_2 += 10;
  return n_plus_2 - m_plus_1;
}


int main(){
  long long n = 0, m = 0;
  std::cin >> n;
  std::cin >> m;
  clock_t tStart = clock();

  // Finonacci Number
  //std::cout << Fibonacci(n);
  //std::cout << FibonacciFast(n) << std::endl;

  // Last digit of a large Finonacci Number
  //std::cout << LastDigitOfFinonacci(n) << std::endl;

  // Huge Finonacci Number modulom
  //std::cout << HugeFinonacciModul(n, m) << std::endl;

  // Sum of Fibonacci
  //std::cout << SumOfFibonacci(n) << std::endl;

  // Patrial Sum of Fibonacci
  std::cout << PartialSumOfFibonacci(n, m) << std::endl;

  std::cout << "Time taken:\n" << (double)(clock() - tStart)/CLOCKS_PER_SEC << " s" << std::endl;
  return 0;
}
