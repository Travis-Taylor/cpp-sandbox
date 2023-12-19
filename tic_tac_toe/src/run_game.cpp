#include "tic_tac_toe.h"
#include <stdlib.h>

void exit_if_win(MoveResult res) {
  if (res == MoveResult::WIN) {
    std::cout << "End of game!" << std::endl;
    exit(0); 
  }
}

int main() {
  TicTacToe game{6};
  game.PrintBoard();
  exit_if_win(game.MakeMove(0, 0));
  game.PrintBoard();
  exit_if_win(game.MakeMove(2, 2));
  game.PrintBoard();
  exit_if_win(game.MakeMove(0, 2));
  game.PrintBoard();
  exit_if_win(game.MakeMove(2, 1));
  game.PrintBoard();
  exit_if_win(game.MakeMove(0, 1));

  return 0;
}
