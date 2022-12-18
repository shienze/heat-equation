cmake_minimum_required(VERSION 3.23)
project(heat_equation)

set(CMAKE_CXX_STANDARD 14)

add_executable(heat_equation PDEex.cpp PDEim.cpp explicit.cpp implicit.cpp LU.cpp)
