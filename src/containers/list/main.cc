#include <algorithm>
#include <iostream>
// #include <list>

#include "./list.h"

s21::list<int> funs() {
  s21::list<int> list{32, 2, 1, 4};
  return list;
}

int main() {
  s21::list<int> val1{1, 2, 3};
  s21::list<int> val2{4, 5, 6, 7};

  val1.swap(val2);
  val1.swap(val1);

  for (auto a : val1) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  for (auto a : val2) {
    std::cout << a << " ";
  }
  return 0;
}