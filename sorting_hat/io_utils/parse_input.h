#include <iostream>

int parse_input(void) {
//  std::cout << "Parsing input from external lib\n";
  float in;
  std::cin >> in;
  return static_cast<int>(in);
}
