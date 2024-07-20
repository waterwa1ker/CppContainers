#include <algorithm>
#include <iostream>
// #include <list>

#include "./list.h"

s21::list<int> funs() {
  s21::list<int> list{32, 2, 1, 4};
  return list;
}

int main() {
  s21::list<int> val{1, 3, 4};

  val.push_front(0);

  for (auto a : val) {
    std::cout << a << " ";
  }

  // std::list<int> sval{1, 2, 3};

  // sval.pop_back();

  // for (auto a : sval) {
  //   std::cout << a << " ";
  // }

  return 0;
}