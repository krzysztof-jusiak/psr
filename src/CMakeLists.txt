add_executable(psr main.cpp)
target_include_directories(psr PRIVATE ../include SYSTEM
  ${CMAKE_SOURCE_DIR}/vendor)
