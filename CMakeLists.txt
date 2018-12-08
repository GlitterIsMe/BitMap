cmake_minimum_required(VERSION 3.12)
project(bitmap)

set(CMAKE_CXX_STANDARD 14)

set(SRC main.cpp
        bit_map.cc)

add_executable(bitmap ${SRC})