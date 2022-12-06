include_directories(${CMAKE_SOURCE_DIR}/io_utils/include)

add_executable(Guess guess.cpp)
add_executable(Squares squares.cpp)
add_executable(Bottles bottles.cpp)
add_executable(Fizzbuzz fizzbuzz.cpp)
target_link_libraries(Guess io_utils)

install (TARGETS Guess Squares Bottles Fizzbuzz DESTINATION "${CMAKE_BINARY_DIR}/install")
