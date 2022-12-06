add_library(Roman_LIB
    Roman.cpp)

add_executable(Eval eval.cpp)
target_link_libraries(Eval Roman_LIB)
include_directories("${PROJECT_SOURCE_DIR}/include")

install (TARGETS Eval DESTINATION "${CMAKE_BINARY_DIR}/install")
