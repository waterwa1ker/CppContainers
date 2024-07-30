#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

// s21::list<int> funs() {
//   s21::list<int> list{32, 2, 1, 4};
//   return list;
// }

int main() {
  std::list<int> val2{};
  val2.erase(val2.end());
  std::cout << "std:\n";
  for (auto a : val2) {
    std::cout << a << " ";
  }
  return 0;
}