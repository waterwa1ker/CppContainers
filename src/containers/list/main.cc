#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

// s21::list<int> funs() {
//   s21::list<int> list{32, 2, 1, 4};
//   return list;
// }

int main() {
  s21::list<int> val1{3, 2};
  s21::list<int> val2{1, 3, 2};

  val1.merge(val2);
  std::cout << "S21:\n";
  for (auto a : val1) {
    std::cout << a << " ";
  }

  std::list<int> sval1{3, 2};
  std::list<int> sval2{1, 3, 2};

  sval1.merge(sval2);
  std::cout << "\nSTD:\n";
  for (auto a : sval1) {
    std::cout << a << " ";
  }

  return 0;
}