cmake_minimum_required(VERSION 4.3)
project(c_exercises C)

set(CMAKE_C_STANDARD 11)

include_directories("Exercise 1")
include_directories("Exercise 2")
include_directories("Exercise 3")
include_directories("Exercise 4")
include_directories("Exercise 5")
include_directories("Exercise 6")
include_directories("Exercise 7")
include_directories("Exercise 8")
include_directories("Exercise 9")
include_directories("Exercise 10")
include_directories("Exercise 11")
include_directories("Exercise 12")


add_executable(c_exercises
        "Project/main.c"
        "Project/headers.h"
)
