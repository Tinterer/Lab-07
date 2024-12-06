cmake_minimum_required(VERSION 3.10)

project(Lab-07)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O2 -Wall -Werror -pedantic")

enable_testing()

find_package(GTest REQUIRED)

add_executable(main main.cpp ext.cpp)

target_link_libraries(main PRIVATE GTest::GTest GTest::Main)
