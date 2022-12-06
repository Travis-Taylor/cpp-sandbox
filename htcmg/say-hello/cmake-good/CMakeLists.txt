add_executable(cmake-good main.cpp)

target_link_libraries(cmake-good PRIVATE say-hello)

install(TARGETS cmake-good 
    DESTINATION ${CMAKE_BINARY_DIR})
