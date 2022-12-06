#include <iostream>
#include <math.h>

int main() {
  
  std::cout << "Simple square calculation routine\n";

  int i = 0;
  int square = 0;

  while (i < 10) {
    square = pow(i,2);
    std::cout << i << "\t" << square << std::endl;
    i++;
  }
}

