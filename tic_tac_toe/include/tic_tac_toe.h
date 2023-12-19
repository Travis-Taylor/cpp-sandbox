#pragma once

#include <vector>
#include <iostream>

enum MoveResult {
  INVALID = 0,
  WIN,
  CONTINUE,
};

enum Player {
  NEITHER = -1,
  FIRST = 0,
  SECOND = 1,
};

class TicTacToe {
  public:
  // Create a public interface to create and size a new board.
  TicTacToe(int size);
  
  // Create a method that provides an API to make a new move. 
  // This should also provide the result of the move (invalid, win, continue, etc.)
  // Performance should scale linearly (or better) with board size. 
  MoveResult MakeMove(int col, int row);

  void PrintBoard() const;
  
  private:
  // storage for the game state.
  int size_;
  bool game_over_;
  Player last_player_;
  // board of n x n spaces storing player's selection
  std::vector<std::vector<Player>> board_;
  // stored total per-column for each player
  std::vector<std::pair<int, int>> col_totals_;
  // stored total per-row for each player
  std::vector<std::pair<int, int>> row_totals_;
  // stored total along the diagonals per-player.
  // first is primary diag, second is secondary
  std::vector<std::pair<int, int>> diag_totals_;

  // Helper to fetch the player's total for the given col, row, or diag total
  int GetPlayerTotal(Player player, std::pair<int, int>) const;
  // Helper to increment the player's count for the given total
  void AddPlayerTotal(Player player, std::pair<int, int>&);
  // Check if the player just won
  bool CheckWin(Player, int, int) const;
};

