cmake_minimum_required(VERSION 3.10)

project(MyProject C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(app main.c functions.c)
target_link_libraries(app m) #m = libm.so
