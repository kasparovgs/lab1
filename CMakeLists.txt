cmake_minimum_required(VERSION 3.16)

project(lab1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

add_library(lab1 funcs.h funcs.cpp dialog.cpp dialog.h logic.h logic.cpp)

link_libraries(lab1)

add_executable(main main.cpp)