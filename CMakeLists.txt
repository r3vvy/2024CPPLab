cmake_minimum_required(VERSION 3.10)

project(2024CPPLab)

find_package(fmt CONFIG REQUIRED)

add_executable(2024CPPLab 2024CPPLab.cpp)

target_link_libraries(2024CPPLab PRIVATE fmt::fmt)