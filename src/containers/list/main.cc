#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

// s21::list<int> funs() {
//   s21::list<int> list{32, 2, 1, 4};
//   return list;
// }

int main() {
  s21::list<int> val1{1, 4, 3};
  // std::list<int> val2{4};
  // val1.merge(val2);
  val1.insert(val1.begin(), 8);
  std::cout << "std:\n";
  for (auto a : val1) {
    std::cout << a << " ";
  }
  return 0;
}