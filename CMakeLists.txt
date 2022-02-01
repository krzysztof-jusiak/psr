cmake_minimum_required(VERSION 3.17)

project(psr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
  "-Wall"
  "-Wextra"
  "-Werror"
  "-Wfatal-errors"
  "-pedantic"
  "-pedantic-errors"
)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
