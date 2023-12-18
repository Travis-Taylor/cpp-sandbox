add_library(TicTacToe_LIB
  tic_tac_toe.cpp)

add_executable(TicTacToe run_game.cpp)
target_link_libraries(TicTacToe TicTacToe_LIB)
include_directories("${PROJECT_SOURCE_DIR}/include")
