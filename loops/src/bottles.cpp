#include <iostream>

int main(void) {
  std::cout << "Ready for a rousing counting song??\n\n";

  for (int i = 99; i > 0;) {

    std::cout << i << " bottles of beer on the wall,\n"
              << i << " bottles of beer!\n"
              << "Take one down, pass it around,\n"
              << --i << " bottles of beer on the wall!\n\n";
  }
}
