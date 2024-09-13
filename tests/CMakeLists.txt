cmake_minimum_required(VERSION 3.16)
project(lab1_tests)

enable_testing()

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_library(lab1 ../funcs.h ../funcs.cpp ../dialog.cpp ../dialog.h ../logic.h ../logic.cpp)

# подключаем Google Test
find_package(GTest REQUIRED)

add_executable(runTests tests.cpp)
target_link_libraries(runTests GTest::gtest GTest::gtest_main lab1)

add_test(NAME MyTests COMMAND runTests)
