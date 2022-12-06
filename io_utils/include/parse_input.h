#include <iostream>

int parse_int(void) {
  float in;
  std::cin >> in;
  return static_cast<int>(in);
}

std::string parse_string(void) {
  std::string in;
  // TODO parse it?
  std::cin >> in;
  return in;
}
