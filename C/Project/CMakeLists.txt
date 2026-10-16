cmake_minimum_required(VERSION 3.10)
project(akselauncher C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(akselauncher
    main.c
    menu_functions.c
    game_functions.c
    string_helpers.c
)

if(NOT MSVC)
    target_compile_options(akselauncher PRIVATE -Wall -Wextra)
endif()

configure_file(metadata.txt ${CMAKE_BINARY_DIR}/metadata.txt COPYONLY)
