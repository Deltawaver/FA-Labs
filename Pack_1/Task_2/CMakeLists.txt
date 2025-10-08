cmake_minimum_required(VERSION 3.10)

# Название проекта и язык
project(MyProject C)

# Указываем стандарт C (например, C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Создаём исполняемый файл 'app' из файла main.c
add_executable(app main.c functions.c)
target_link_libraries(app m) #m = libm.so