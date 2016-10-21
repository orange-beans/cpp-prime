#include <iostream>
#include "./lib/Sales_item.h"

void generateReport();

int main() {
  // Sales_item item1, item2;
  // std::cin >> item1 >> item2; // read a pair of transactions
  // std::cout << item1 + item2 << std::endl; // print their sum
  generateReport();
  return 0;
}

void generateReport() {
  Sales_item trans, total;
  int counter = 0;
  std::cout << "Enter multiple sales:" << std::endl;
  while(std::cin >> trans) {
    if (counter == 0) {
      total = trans;
    } else {
      if (trans.isbn() == total.isbn()) {
        total += trans;
      } else {
        std::cout << total << std::endl;
        total = trans;
      }
    }
    counter++;
  }
}
