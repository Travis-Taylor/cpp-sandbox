# Following https://cmake.org/cmake-tutorial/

cmake_minimum_required (VERSION 2.6)
project (Sorting_Hat)

# Project version
set (Sorting_Hat_VERSION_MAJOR 1)
set (Sorting_Hat_VERSION_MINOR 0)

# configure header to reference version number
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# search for config file in current dir
include_directories("${PROJECT_BINARY_DIR}")

# additional util library
option (USE_IO_UTILS
        "Use external io utilities to read input" ON)

if (USE_IO_UTILS)
  include_directories("${PROJECT_SOURCE_DIR}/io_utils")
  add_subdirectory(io_utils)
  # EXTRA_LIBS to encompass any optional libs to build with
  set (EXTRA_LIBS ${EXTRA_LIBS} io_utils)
endif (USE_IO_UTILS)


# specify the executable
add_executable(Sorting_Hat sorting_hat.cpp)
# specify libraries to link
target_link_libraries(Sorting_Hat ${EXTRA_LIBS})


# add install targets
install (TARGETS Sorting_Hat DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
        DESTINATION include)

