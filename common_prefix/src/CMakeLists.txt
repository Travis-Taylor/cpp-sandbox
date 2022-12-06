add_library(CommonPrefix_LIB
    prefix.cpp)

add_executable(Eval eval.cpp)
target_link_libraries(Eval CommonPrefix_LIB)
include_directories("${PROJECT_SOURCE_DIR}/include")
