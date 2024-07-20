#include <algorithm>
#include <iostream>
// #include <list>

#include "./list.h"

s21::list<int> funs() {
  s21::list<int> list{32, 2, 1, 4};
  return list;
}

int main() {
  s21::list<int> slist{1, 2, 3};

  s21::list<int> copy;

  copy = funs();

  // std::cout << "OWN LIST\n";
  for (auto a : copy) {
    std::cout << a << " ";
  }

  // std::cout << std::endl
  //           << slist.front() << std::endl
  //           << slist.back() << std::endl;

  // std::cout << "LIST\n";
  // std::list<int> list{1, 2, 3, 4};

  // for (auto a : list) {
  //   std::cout << a << " ";
  // }

  // std::cout << std::endl
  //           << list.front() << std::endl
  //           << list.back() << std::endl;

  return 0;
}