#include <algorithm>
#include <iostream>

#include "./list.h"

int main() {
  // std::list<int> list{1, 2, 3, 4};
  // s21::list<int> list{1, 2, 3, 4};
  s21::list<int> slist(4);

  for (auto a : slist) {
    std::cout << a << " ";
  }

  std::cout << std::endl
            << slist.front() << std::endl
            << slist.back() << std::endl;
  return 0;
}