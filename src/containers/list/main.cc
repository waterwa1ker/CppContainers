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
  s21::list<int> val2{5, 4, 5};

  std::list<int> sval1{1, 4, 3};
  std::list<int> sval2{5, 4, 5};

  // val2.max_size();

  val1.splice(val2.end(), val2);
  sval1.splice(sval2.end(), sval2);

  std::cout << "s21\n";
  for (auto a : val1) {
    std::cout << a << " ";
  }
  std::cout << "\nstd\n";
  for (auto a : sval1) {
    std::cout << a << " ";
  }
  return 0;
}