include_directories(${CMAKE_SOURCE_DIR}/io_utils/include)
link_directories(${CMAKE_SOURCE_DIR}/io_utils/src)
add_executable(RPSLS RPSLS.cpp)
target_link_libraries(RPSLS io_utils)

install (TARGETS RPSLS DESTINATION "${CMAKE_BINARY_DIR}/install")
