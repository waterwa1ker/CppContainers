#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

// s21::list<int> funs() {
//   s21::list<int> list{32, 2, 1, 4};
//   return list;
// }

int main() {
  s21::list<int> val1{};
  std::list<int> val2{};

  // val.sort();
  for (auto a : val1) {
    std::cout << a << " ";
  }
  val1.unique();
  std::cout << std::endl << "S21\n";
  for (auto a : val1) {
    std::cout << a << " ";
  }
  val2.unique();
  std::cout << "std:\n";
  for (auto a : val2) {
    std::cout << a << " ";
  }
  return 0;
}