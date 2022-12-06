#include <iostream>
#include "parse_input.h"

int main() {

  int guess;

  int tries = 0;

  std::cout << "I have a number 1-500.\n"
            << "Guess which one: ";
  guess = parse_int();

  while (guess != 399 && tries < 50) {

    std::cout << "That's clearly wrong.\nGuess again: ";
    tries++;
    guess = parse_int();
  }

  if (guess == 399) {
    std::cout << "You got it!\n";
    return 0;
  }

  std::cout << "You're beyond help\n";
}
