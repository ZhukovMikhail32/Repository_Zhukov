cmake_minimum_required(VERSION 3.10)
project(Iomanip)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(tests_sources ./tests/iomanip.cpp ./include/iomanip.hpp)

include_directories(include)
add_subdirectory(Catch2)

add_executable(tests ${tests_sources})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)