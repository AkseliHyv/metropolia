cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

set(PICO_SDK_PATH /home/akseli/pico/pico-sdk)
include(pico_sdk_import.cmake)
project(Lab_3 C CXX ASM)

pico_sdk_init()

add_executable(Lab_3
        headers.h
        main.c
)

target_link_libraries(Lab_3
        pico_stdlib
)

pico_enable_stdio_uart(Lab_3 1)
pico_enable_stdio_usb(Lab_3 0)

pico_add_extra_outputs(Lab_3)
