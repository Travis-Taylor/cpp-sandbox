#include <iostream>

int main(void) {
  
  for (int i = 1; i <= 100; i++) {
    if (!(i%3))  // multiple of 3
      std::cout << "Fizz";
    
    if (!(i%5))  // multiple of 5
      std::cout << "Buzz";
    
    if ((i%3)*(i%5))  // if neither
      std::cout << i;
    
    std::cout << std::endl;
      
  }
}
