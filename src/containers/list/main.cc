#include <algorithm>
#include <iostream>
#include <list>

#include "./list.h"

int main() {
  // std::list<int> list{1, 2, 3, 4};
  // s21::list<int> list{1, 2, 3, 4};
  s21::list<int> list(4);

  for (auto a : list) {
    std::cout << a << std::endl;
  }
  // s21::list<int> some(1);
  return 0;
}