add_library(say-hello
    src/hello.cpp
    src/hello.hpp
    )

target_include_directories(say-hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(cmake-good)

target_compile_definitions(say-hello PUBLIC SAY_HELLO_VERSION=1)
