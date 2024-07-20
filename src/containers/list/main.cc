#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

s21::list<int> funs() {
  s21::list<int> list{32, 2, 1, 4};
  return list;
}

int main() {
  s21::list<int> val{1, 2, 3, 4};

  for (auto a : val) {
    std::cout << a << " ";
  }

  val.clear();

  for (auto a : val) {
    std::cout << a << " ";
  }

  std::cout << val.size();

  return 0;
}