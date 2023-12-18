#include <stdexcept>
#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int size) {
  if (size <= 0) {
    throw std::runtime_error("Size invalid, provide positive int");
  }
  size_ = size;
  last_player_ = Player::NEITHER;
  // Initialize board
  board_.reserve(size);
  for (int col = 0; col < size; col++) {
    std::vector<Player> column;
    for (int row = 0; row < size; row++) {
      column.push_back(Player::NEITHER); 
    }
    board_.push_back(column);
  }
  // Initialize running count of players' totals per-column, row, and diag
  col_totals_.reserve(size);
  for (int xx = 0; xx < size; xx++) {
    col_totals_.push_back(std::make_pair(0, 0));
  }
  row_totals_.reserve(size);
  for (int yy = 0; yy < size; yy++) {
    row_totals_.push_back(std::make_pair(0, 0));
  }
  diag_totals_ = {std::make_pair(0, 0), std::make_pair(0,0)};
  game_over_ = false;
  std::cout << "Ready to start a " << size << "x" << size << 
    " game of tic-tac-toe!" << std::endl;
}

MoveResult TicTacToe::MakeMove(int col, int row) {
  Player current_player = static_cast<Player>((last_player_ + 1) % 2);
  last_player_ = current_player;
  if (col >= size_ || row >= size_) {
    std::cout << "Invalid choice, must be 0-indexed position within " 
      << size_ << "-sized board" << std::endl;
   return MoveResult::INVALID; 
  }
  board_[col][row] = current_player;
  AddPlayerTotal(current_player, col_totals_[col]);
  AddPlayerTotal(current_player, row_totals_[row]);
  // Add to primary diagonal
  if (row == col) {
    AddPlayerTotal(current_player, diag_totals_[0]);
  }
  // Add to secondary diagonal
  if (row + col == size_ - 1) {
    AddPlayerTotal(current_player, diag_totals_[1]);
  }
  if (CheckWin(current_player, col, row)) {
    std::cout << "Player " << static_cast<int>(current_player) << " wins!" << std::endl;
    game_over_ = true;
    return MoveResult::WIN;
  }
  return MoveResult::CONTINUE;
}

void TicTacToe::AddPlayerTotal(Player player, std::pair<int, int>& totals) {
  if (player == Player::FIRST) {
    const int new_total = totals.first + 1;
    totals = std::make_pair(new_total, totals.second);
    return;
  }
  if (player == Player::SECOND) {
    const int new_total = totals.second + 1;
    totals = std::make_pair(totals.first, new_total);
    return;
  }
}

int TicTacToe::GetPlayerTotal(Player player, std::pair<int, int> totals) const {
  if (player == Player::FIRST) {
    return totals.first;
  }
  if (player == Player::SECOND) {
    return totals.second;
  }
  return 0;
}

bool TicTacToe::CheckWin(Player player, int col, int row) const {
  if (GetPlayerTotal(player, col_totals_[col]) == size_) {
    return true;
  }
  if (GetPlayerTotal(player, row_totals_[row]) == size_) {
    return true;
  }
  if (GetPlayerTotal(player, diag_totals_[0]) == size_) {
    return true;
  }
  if (GetPlayerTotal(player, diag_totals_[1]) == size_) {
    return true;
  }
  return false;
}

void TicTacToe::PrintBoard() const {
  std::cout << "Player1 = X, Player2 = O" << std::endl;
  // TODO
}