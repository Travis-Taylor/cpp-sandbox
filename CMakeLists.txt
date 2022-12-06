cmake_minimum_required(VERSION 3.5)

Project(Training)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(class_work)
add_subdirectory(loops)
add_subdirectory(ジャンケンポン)
add_subdirectory(io_utils)

macro (print_all_variables)
  message (STATUS "print_all_variables---------------------------------------{")
  get_cmake_property(_variableNames VARIABLES)
  foreach (_variableName ${_variableNames})
    message (STATUS "${_variableName}=${${_variableName}}")
  endforeach()
  message (STATUS "print_all_variables---------------------------------------}")
endmacro()

#print_all_variables()
