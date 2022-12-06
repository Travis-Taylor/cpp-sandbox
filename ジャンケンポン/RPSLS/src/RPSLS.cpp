/* Rock paper scissors lizard spock (ジャンケンポン。。。リザルドスポック)
  5-way rock-paper-scissors, following https://www.codecademy.com/courses/learn-c-plus-plus/projects/rock-paper-scissors-lizard-spock
  Travis Taylor, winter 2019
*/

#include <stdlib.h>
#include <iostream>

#ifdef USE_IO_UTILS
#include parse_input.h
#endif


#ifndef USE_IO_UTILS
int parse_int(void) {
  float in;
  std::cin >> in;
  return static_cast<int>(in);
}
std::string parse_string(void) {
  std::string in;
  std::cin >> in;
  return in;
}
#endif

enum hand {rock = 1, paper, scissors, lizard, spock};

void plain(void);
void fancy(void);
bool user_win(hand);
bool comp_win(hand);
bool tie(hand);
std::string to_string(hand);



int main() {
  srand(time(NULL));
  
  std::cout << "First things first:\n"
            << "Are you playing the plain version, or the FANCY one?\n"
            << "\t> ";

  std::string game = parse_string();
  if (game == "p" or game == "plain" or game == "Plain" or game == "PLAIN") 
    plain();
  else
    fancy();

}
void plain(void) {
  std::cout << "Plain, huh?\nAll right....\n\n\n";
  hand computer;
  hand user;

  bool again = true;
  while (again) { 

    std::cout << "==============================\n"
              << "叩いて被ってジャンケンポン！！\n"
              << "==============================\n";

    std::cout << "1) ROCK\n"
              << "2) PAPER\n"
              << "3) SCISSORS\n";

    std::cout << "Shoot!\n\t> ";
    computer = hand(rand() % 3 + 1);

    user = (hand)parse_int();

    switch (user) {
      case rock:
        switch (computer) {
          case scissors:
          case lizard:
            again = user_win(computer);
            break;
          case paper:
          case spock:
            again = comp_win(computer);
            break;
          case rock:
            again = tie(computer);
            break;
        }
        break;
      case paper:
        switch (computer) {
          case rock:
          case spock:
            again = user_win(computer);
            break;
          case scissors:
          case lizard:
            again = comp_win(computer);
            break;
          case paper:
            again = tie(computer);
            break;
        }
        break;
      case scissors:
        switch (computer) {
          case paper:
          case lizard:
            again = user_win(computer);
            break;
          case rock:
          case spock:
            again = comp_win(computer);
            break;
          case scissors:
            again = tie(computer);
            break;
        }
        break;
      default:
        std::cout << "Answer format is the number corresponding to your choice\n\t> ";
        break;
    }
  }
}

void fancy(void) {
  std::cout << "I figured you would. All right...\n\n\n";
  hand computer;
  hand user;

  bool again = true;
  while (again) {

  
    std::cout << "====================================================\n"
              << "叩いて被ってジャンケンポン。。。リザルドスポック！！\n"
              << "====================================================\n";

    std::cout << "1) ROCK\n"
              << "2) PAPER\n"
              << "3) SCISSORS\n"
              << "4) LIZARD\n"
              << "5) SPOCK\n";

    std::cout << "Shoot!\n\t> ";
    computer = hand(rand() % 5 + 1);

    user = (hand)parse_int();
  
    switch (user) {
      case rock:
        switch (computer) {
          case scissors:
          case lizard:
            again = user_win(computer);
            break;
          case paper:
          case spock:
            again = comp_win(computer);
            break;
          case rock:
            again = tie(computer);
            break;
        }
        break;
      case paper:
        switch (computer) {
          case rock:
          case spock:
            again = user_win(computer);
            break;
          case scissors:
          case lizard:
            again = comp_win(computer);
            break;
          case paper:
            again = tie(computer);
            break;
        }
        break;
      case scissors:
        switch (computer) {
          case paper:
          case lizard:
            again = user_win(computer);
            break;
          case rock:
          case spock:
            again = comp_win(computer);
            break;
          case scissors:
            again = tie(computer);
            break;
        }
        break;
      case spock:
        switch (computer) {
          case rock:
          case scissors:
            again = user_win(computer);
            break;
          case paper:
          case lizard:
            again = comp_win(computer);
            break;
          case spock:
            again = tie(computer);
            break;
        }
        break;
      case lizard:
        switch (computer) {
          case paper:
          case spock:
            again = user_win(computer);
            break;
          case scissors:
          case rock:
            again = comp_win(computer);
            break;
          case lizard:
            again = tie(computer);
            break;
        }
        break;
      default:
        std::cout << "Answer format is the number corresponding to your choice\n\t> ";
        break;
    }
  
  }
  
}

bool user_win(hand comp) {
  std::cout << "Computer chose " << to_string(comp) << "\nYou won!\n"
            << "Play again? (y/n):\t";
  std::string in = parse_string(); 
  return (in == "y" or in == "Y");
}

bool comp_win(hand comp) {
  std::cout << "Computer chose " << to_string(comp) << "\nYou lost!\n"
            << "Play again? (y/n):\t";
  std::string in = parse_string(); 
  return (in == "y" or in == "Y");
}

bool tie(hand comp) {
  std::cout << "Woah! Computer chose " << to_string(comp) << " too!\n"
            << "Play again? (y/n):\t";
  std::string in = parse_string();
  return (in == "y" or in == "Y");
}

std::string to_string(hand h) {
  switch (h) {
    case rock:
      return "rock";
    case paper:
      return "paper";
    case scissors:
      return "scissors";
    case lizard:
      return "lizard";
    case spock:
      return "Spock";
    default:
      return ".... I'm not sure what that is.\n";
  }
}
