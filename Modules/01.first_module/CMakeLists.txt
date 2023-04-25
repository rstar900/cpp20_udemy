cmake_minimum_required(VERSION 3.25)
project(01_first_module)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fmodules-ts")

add_executable(main main.cpp my_first_module.cxx)
