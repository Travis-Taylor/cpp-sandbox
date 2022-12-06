#include_directories(${CMAKE_CURRENT_BINARY_DIR})

#add_library(io_utils parse_input.h)

#install (TARGETS io_utils DESTINATION bin)
#install (FILES parse_input.h DESTINATION include)

#set_target_properties(io_utils PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(src)
