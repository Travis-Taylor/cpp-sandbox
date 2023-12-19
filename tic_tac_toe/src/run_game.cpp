#include "tic_tac_toe.h"
#include <stdlib.h>
#include <string>
#include <exception>

std::pair<int, int> GetUserSelection(Player p) {
  const char* player = p == Player::FIRST ? "Player 1" : "Player 2";
  std::string choice;
  while (true) {
    std::cout << player << ": What square will you choose (x,y)? ";
    std::cin >> choice;
    const std::size_t comma = choice.find(",");
    if (comma == std::string::npos) {
      std::cout << "Invalid choice - must be comma-delimited pair" << std::endl;
      continue;
    }
    int col = -1, row = -1;
    try {
      const std::string col_str = choice.substr(0, comma);
      col = stoi(col_str);
      const std::string row_str = choice.substr(comma + 1);
      row = stoi(row_str);
    }
    catch (std::exception) {
      std::cout << "Invalid choice - must be integer pair" << std::endl;
      continue;
    }
    return std::make_pair(col, row);
  }
}

int main() {
  std::string size_input;
  std::cout << "How big should the tic-tac-toe board be? ";
  std::cin >> size_input;
  const int board_size = stoi(size_input);
  TicTacToe game{board_size};
  MoveResult res = MoveResult::CONTINUE;
  while (res != MoveResult::WIN) {
    //for (const Player p : [Player::FIRST, Player::SECOND]) {
    for (int ii = 0; ii < 2; ii++) {
      game.PrintBoard();
      const Player p = static_cast<Player>(ii);
      const auto [col, row] = GetUserSelection(p);
      res = game.MakeMove(col, row);
      while (res == MoveResult::INVALID) {
        const auto [col, row] = GetUserSelection(p);
        res = game.MakeMove(col, row);
      }
      if (res == MoveResult::WIN) {
        game.PrintBoard();
        break;
      }
    }
  }

  return 0;
}
