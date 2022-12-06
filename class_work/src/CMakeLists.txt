### below doesn't work when just building local proj, would need local copy of io_utils
# include_directories(${CMAKE_SOURCE_DIR}/io_utils/include)
# target_link_libraries(Classes io_utils)

add_library(Dog_LIB 
  Dog.cpp)

add_executable(Classes classes.cpp)
target_link_libraries(Classes Dog_LIB)
include_directories("${PROJECT_SOURCE_DIR}/include")

install (TARGETS Classes DESTINATION "${CMAKE_BINARY_DIR}/install")


