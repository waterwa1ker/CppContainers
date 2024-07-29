#include <algorithm>
#include <iostream>
// #include <list>

#include "./list.h"

// s21::list<int> funs() {
//   s21::list<int> list{32, 2, 1, 4};
//   return list;
// }

int main() {
  s21::list<int> val{1, 5, -3, 2, 0, 34, 0, 4, 5};
  std::cout << "Before: ";
  for (auto a : val) {
    std::cout << a << " ";
  }
  val.sort();
  std::cout << std::endl << "After: ";
  for (auto a : val) {
    std::cout << a << " ";
  }
  return 0;
}