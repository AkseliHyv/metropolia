cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)
project(Lab_1 C CXX ASM)

pico_sdk_init()

add_executable(Lab_1
        headers.h
        main.c
)

target_link_libraries(Lab_1
        pico_stdlib
        hardware_pwm
)

pico_enable_stdio_uart(Lab_1 1)
pico_enable_stdio_usb(Lab_1 0)

pico_add_extra_outputs(Lab_1)
