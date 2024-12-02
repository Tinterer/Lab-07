cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Lab-03)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror -pedantic)

add_executable(main main.cpp ext.cpp)

