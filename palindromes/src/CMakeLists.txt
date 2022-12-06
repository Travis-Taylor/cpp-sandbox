add_library(Palindrome_LIB
    palindromes.cpp)

add_executable(Eval eval.cpp)
target_link_libraries(Eval Palindrome_LIB)
include_directories("${PROJECT_SOURCE_DIR}/include")
