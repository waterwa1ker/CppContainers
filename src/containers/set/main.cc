#include <iostream>

/**
 *
 * \file
 *
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
int main(int argc, char** argv) {
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  std::cout << "Hello, world! This is an example" << std::endl;
  return 0;
}
